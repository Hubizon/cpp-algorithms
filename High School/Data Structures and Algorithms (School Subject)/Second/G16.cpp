// Hubert Jastrzębski | Satori G16 (Tango down) | 2022-05-22
// https://satori.tcs.uj.edu.pl/contest/7079339/problems/7664194

#include <iostream>
#include <functional>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int z;
    cin >> z;
    while (z--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> G(n);
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            G[--a].push_back(--b);
            G[b].push_back(a);
        }

        int cnt = 0;
        vector<ll> R(n);
        vector<pair<int, int>> D(n, { -1, -1 });
        function<int(int, int)> DFS = [&](int u, int p) -> int {
          auto& [uID, uLOW] = D[u];
          if (uID != -1) return 0;
          uID = uLOW = cnt++;

          ll res = 0;
          int children = 0;
          for (auto& v : G[u]) {
              if (v == p) continue;
              int dfsr = DFS(v, u);
              auto& [vID, vLOW] = D[v];
              if (vID < uID)
                  uLOW = min(uLOW, vID);
              else if (vLOW < uID)
                  uLOW = min(uLOW, vLOW);
              else {
                  res += dfsr * (dfsr - 1LL);
                  children += dfsr;
              }
          }

          int l = n - children - 1;
          res += l * (l - 1LL);
          R[u] = res;
          return cnt - uID;
        };

        DFS(0, -1);

        for (auto& r : R)
            cout << r << '\n';
    }
}