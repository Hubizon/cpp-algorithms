// Hubert Jastrzębski | Satori G18 (Obóz Babilon) | 2022-11-09
// https://satori.tcs.uj.edu.pl/contest/7808974/problems/7813363

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <array>

using namespace std;

typedef long long ll;
constexpr ll INF = 1e18;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int z;
    cin >> z;
    while (z--) {
        int n, m;
        cin >> n >> m;

        vector<vector<array<int, 5>>> G(n);
        for (int i = 0; i < m; i++) {
            int u, v, w, t, a, l;
            cin >> u >> v >> w >> t >> a >> l;
            G[u - 1].push_back({ v - 1, w, t, a, l });
        }

        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> Q;
        vector<ll> dist(n, INF);
        Q.push({ dist[0] = 0, 0 });

        while (Q.size()) {
            auto [du, u] = Q.top(); Q.pop();
            if (dist[u] != du) continue;
            for (auto [v, w, t, a, l] : G[u]) {
                int x = (t == 0 ? 0 : (du - a + t) % t);
                w += (x >= l) * (t - x);
                if (dist[v] > du + w)
                    Q.push({ dist[v] = du + w, v });
            }
        }

        cout << (dist.back() == INF ? "NIE" : to_string(dist.back())) << '\n';
    }
}