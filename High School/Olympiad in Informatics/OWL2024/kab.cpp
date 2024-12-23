// Hubert Jastrzębski | PREOI / OWL 2024 (Kablówka) | 2024-01-31
// https://sio2.staszic.waw.pl/c/preoi-owl-2024/p/kab/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<array<int, 3>> V(n);
    for (auto& [a, b, k] : V) {
        cin >> a >> b >> k;
    }

    vector<vector<int>> G(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    function<int(int, int, int, int, int)> DFS = [&](int u, int p, int l, int r, int dest) {
      if (u == dest) {
          auto [a, b, k] = V[u];
          if (a <= r && b >= l)
              return k;
          else
              return 0;
      }

      for (auto v : G[u]) {
          if (v == p) continue;
          int x = DFS(v, u, l, r, dest);
          if (x != -1) {
              auto [a, b, k] = V[u];
              if (a <= r && b >= l)
                  return max(x, k);
              else
                  return x;
          }
      }

      return -1;
    };

    for (int i = 0; i < q; i++) {
        int x, y, l, r;
        cin >> x >> y >> l >> r;
        cout << DFS(x - 1, -1, l, r, y - 1) << '\n';
    }
}