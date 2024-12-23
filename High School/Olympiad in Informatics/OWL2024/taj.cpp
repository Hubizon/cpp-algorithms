// Hubert Jastrzębski | PREOI / OWL 2024 (Tajni agenci) | 2024-01-30
// https://sio2.staszic.waw.pl/c/preoi-owl-2024/p/taj/

#include <bits/stdc++.h>

using namespace std;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> V(n);
    for (int i = 1; i < n; i++)
        cin >> V[i];

    vector<vector<int>> G(n);
    for (int i = 0; i < n - 1; i++) {
        int p, q;
        cin >> p >> q;
        --p, --q;
        G[p].push_back(q);
        G[q].push_back(p);
    }

    vector<pair<int, int>> R;
    function<array<int, 3>(int, int, int)> DFS = [&](int u, int p, int d) {
      array<vector<pair<int, int>>, 3> T;
      if (V[u] != 0)
          T[V[u] - 1].push_back({ d, u });
      for (auto v : G[u]) {
          if (v == p) continue;
          auto [type, depth, index] = DFS(v, u, d + 1);
          if (index == -1) continue;
          if (type != 0)
              T[type - 1].push_back({ depth, index });
      }

      sort(T[0].begin(), T[0].end());
      sort(T[1].begin(), T[1].end());
      sort(T[2].begin(), T[2].end());

      if (T[0].size() > 1) {
          for (int i = 0; i < T[0].size() - 1; i++) {
              if (T[0][i].first == T[0][i + 1].first) {
                  R.push_back({ T[0][i].second, T[0][i + 1].second });
                  T[0][i].first = T[0][i + 1].first = -1;
              }
          }
      }

      int i1 = 0, i2 = 0;
      while (i1 < T[1].size() && i2 < T[2].size()) {
          if (T[1][i1].first < T[2][i2].first) {
              R.push_back({ T[1][i1].second, T[2][i2].second });
              T[1][i1].first = T[2][i2].first = -1;
              i1++, i2++;
          }
          else
              i2++;
      }

      array<int, 3> TR = { -1, -1, -1 };
      for (int t = 0; t < 3; t++) {
          for (auto [depth, index] : T[t]) {
              if (depth != -1) {
                  if (TR[0] == -1)
                      TR = { t + 1, depth, index };
                  else {
                      cout << "NIE";
                      exit (0);
                  }
              }
          }
      }

      return TR;
    };

    auto [type, depth, index] = DFS(0, -1, 0);
    if (index != -1)
        cout << "NIE";
    else {
        cout << "TAK\n";
        for (auto [a, b] : R)
            cout << a + 1 << ' ' << b + 1 << '\n';
    }
}