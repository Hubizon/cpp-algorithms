// Hubert Jastrzębski | Satori G22 (Blokada) | 2023-01-31
// https://satori.tcs.uj.edu.pl/contest/7808974/problems/8223351

#include <iostream>
#include <functional>
#include <vector>
#include <queue>
#include <array>

using namespace std;

constexpr int INF = 1e6;
constexpr int INF2 = 1e9;

struct Edge {
  int dest, c, f, id;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int z;
    cin >> z;
    while (z--) {
        int n, m, s, t;
        cin >> n >> m >> s >> t;
        --s, --t;
        s = 2 * s + 1;
        t = 2 * t;
        n *= 2;

        vector<vector<Edge>> G(n);
        for (int i = 0; i < n; i += 2) {
            G[i].push_back({ i + 1, 1, 0, (int)G[i + 1].size() });
            G[i + 1].push_back({ i, 1, 0, (int)G[i].size() - 1 });
        }

        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            --a, --b;
            a *= 2, b *= 2;
            G[a + 1].push_back({ b, INF, 0, (int)G[b].size() });
            G[b].push_back({ a + 1, 0, 0, (int)G[a + 1].size() - 1 });
            G[b + 1].push_back({ a, INF, 0, (int)G[a].size() });
            G[a].push_back({ b + 1, 0, 0, (int)G[b + 1].size() - 1 });
        }

        vector<bool> vis(n);
        while (true) {
            vis = vector<bool>(n); vis[s] = true;
            vector<array<int, 2>> P(n, { -1, -1 }); P[s][0] = s;
            queue<int> Q; Q.push(s);
            while (Q.size()) {
                auto u = Q.front(); Q.pop();
                for (int i = 0; i < G[u].size(); i++) {
                    auto [v, c, f, id] = G[u][i];
                    if (vis[v] || f == c) continue;
                    vis[v] = true;
                    P[v] = { u, i };
                    Q.push(v);
                }
            }

            if (P[t][0] == -1)
                break;

            int m = INF2;
            int v = t;
            while (v != s) {
                auto [u, i] = P[v];
                m = min(m, G[u][i].c - G[u][i].f);
                v = u;
            }
            v = t;
            while (v != s) {
                auto [u, i] = P[v];
                G[u][i].f += m;
                G[v][G[u][i].id].f -= m;
                v = u;
            }
        }

        vector<int> R;
        for (int i = 0; i < n; i += 2) {
            if (i == s - 1 || i == t) continue;
            if (vis[i] && !vis[i + 1])
                R.push_back(i / 2 + 1);
        }

        cout << R.size() << '\n';
        for (auto& r : R)
            cout << r << ' ';
    }
}