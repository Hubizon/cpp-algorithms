// Hubert Jastrzębski | Krajowe Warsztaty Algorytmiczne PREOI KWA 2022 (Ostatnia podróż Śnieżki) | 2022-02-10
// https://sio2.staszic.waw.pl/c/kwa-2022/p/ops/

#include <iostream>
#include <climits>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, ll>>> G(2 * n);
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w; --a, --b;
        G[2 * a].push_back({ 2 * b + 1, w }); // even a -> odd b
        G[2 * a + 1].push_back({ 2 * b, w }); // odd a -> even b
        G[2 * b].push_back({ 2 * a + 1, w }); // even b -> odd b
        G[2 * b + 1].push_back({ 2 * a, w }); // odd b -> even a
    }

    int src, dest;
    cin >> src >> dest; --src, --dest;
    int srce = 2 * src, deste = 2 * dest;
    int srco = 2 * src + 1, desto = 2 * dest + 1;

    vector<ll> dist(2 * n, LLONG_MAX);
    auto Dijkstra = [&](const int src) {
      priority_queue <pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> Q;
      Q.push({ dist[src] = 0, src });
      while (!Q.empty()) {
          auto [d, u] = Q.top(); Q.pop();
          if (d != dist[u]) continue;
          for (auto& [v, w] : G[u]) {
              if (dist[v] > d + w)
                  Q.push({ dist[v] = d + w, v });
          }
      }
    };

    Dijkstra(srce);
    cout << (dist[deste] == LLONG_MAX ? -1 : dist[deste]) << ' ';
    ll res = dist[desto];
    vector<ll>(2 * n, LLONG_MAX).swap(dist);
    Dijkstra(srco);
    res = min(res, dist[deste]);
    cout << (res == LLONG_MAX ? -1 : res);
}