// Hubert Jastrzębski | PREOI / OWL 2024 (Labirynt) | 2024-01-31
// https://sio2.staszic.waw.pl/c/preoi-owl-2024/p/lab/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, s, t;
    cin >> n >> s >> t;
    --s, --t;

    if (s == t) {
        cout << 0;
        exit(0);
    }

    vector<vector<pair<int, int>>> G(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v, --w;
        G[u].push_back({ v, w });
        G[v].push_back({ u, w });
    }

    vector<pair<int, int>> P(n);
    P[t] = { -1, -1 };

    function<void(int)> DFS = [&](int u) {
      for (auto& [v, w] : G[u]) {
          if (P[u].first != v) {
              P[v] = { u, w };
              DFS(v);
          }
      }
    };

    DFS(t);

    int res = 0;
    vector<bool> ownedKeys(n), wantedKeys(n);
    function<void(int, int, int)> getKey = [&](int a, int b, int key) {
      wantedKeys[key] = true;
      vector<pair<int, int>> D;
      vector<bool> vis(n);
      function<int(int, int)> wDFS = [&](int u, int chamber) {
        vis[u] = true;
        if (u == chamber)
            return 0;
        for (auto& [v, w] : G[u]) {
            if (!vis[v]) {
                if (w != -1)
                    D.push_back({ w, u });
                auto dist = wDFS(v, chamber);
                if (dist != -1)
                    return dist + 1;
                if (w != -1)
                    D.pop_back();
            }
        }
        return -1;
      };

      int distAK = wDFS(a, key);
      vis = vector<bool>(n);
      int distKB = wDFS(key, b);

      int cnt = 0, prev = a;
      for (auto [d, c] : D) {
          if (!ownedKeys[d]) {
              cnt++;
              if (wantedKeys[d]) {
                  cout << -1;
                  exit (0);
              }
              getKey(prev, c, d);
              prev = c;
          }
      }

      if (cnt == 0)
          res += distAK + distKB;
      else
          getKey(prev, b, key);
      ownedKeys[key] = true;
    };

    int pos = s, prev = s, r = 0;
    while (pos != t) {
        auto [p, key] = P[pos];
        if (key != -1 && !ownedKeys[key]) {
            getKey(prev, pos, key);
            prev = pos;
            r = 0;
        }
        pos = p;
        r++;
    }

    cout << res + r;
}