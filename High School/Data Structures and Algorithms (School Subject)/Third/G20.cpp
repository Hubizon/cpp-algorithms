// Hubert Jastrzębski | Satori G20 (Dyplomacja) | 2023-01-15
// https://satori.tcs.uj.edu.pl/contest/7808974/problems/8178034

#include <iostream>
#include <functional>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int z;
    cin >> z;
    while (z--) {
        int n1, n2, m;
        cin >> n1 >> n2 >> m;

        vector<vector<int>> G(n1);
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            --a, --b;
            G[a].push_back(b);
        }

        vector<int> L(n1, -1), R(n2, -1);
        vector<bool> vis(n1);
        function<bool(int)> DFS = [&](int u) {
          if (vis[u]) return false;
          vis[u] = true;
          for (auto& v : G[u]) {
              if (v != L[u] && (R[v] == -1 || DFS(R[v]))) {
                  L[u] = v, R[v] = u;
                  return true;
              }
          }
          return false;
        };

        bool relax = true;
        while (relax) {
            relax = false;
            vis = vector<bool>(n1);
            for (int i = 0; i < n1; i++)
                if (L[i] == -1 && DFS(i))
                    relax = true;
        }

        int res = 0;
        for (int i = 0; i < n1; i++)
            res += (L[i] != -1);

        cout << res << '\n';
    }
}