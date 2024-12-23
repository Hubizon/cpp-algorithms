// Hubert Jastrzębski | Satori G21 (Przepływ) | 	2023-01-29
// https://satori.tcs.uj.edu.pl/contest/7808974/problems/8223263

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int z;
    cin >> z;
    while (z--) {
        int n, m, s, t;
        cin >> n >> m >> s >> t;
        --s, --t;

        vector<vector<int>> G(n);
        vector<vector<ll>> C(n, vector<ll>(n)), F(n, vector<ll>(n));
        for (int i = 0; i < m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            --a, --b;
            C[a][b] += c;
            G[a].push_back(b);
            G[b].push_back(a);
        }

        while (true) {
            vector<int> P(n, -1); P[s] = s;
            queue<int> Q; Q.push(s);
            while (Q.size()) {
                auto u = Q.front(); Q.pop();
                for (auto& v : G[u]) {
                    if (P[v] != -1 || F[u][v] == C[u][v]) continue;
                    P[v] = u;
                    Q.push(v);
                }
            }

            if (P[t] == -1)
                break;

            ll m = INT64_MAX;
            int v = t;
            while (v != s) {
                int u = P[v];
                m = min(m, C[u][v] - F[u][v]);
                v = u;
            }
            v = t;
            while (v != s) {
                int u = P[v];
                F[u][v] += m;
                F[v][u] -= m;
                v = u;
            }
        }

        ll res = 0;
        for (auto& f : F[s])
            res += f;

        cout << res << '\n';
    }
}