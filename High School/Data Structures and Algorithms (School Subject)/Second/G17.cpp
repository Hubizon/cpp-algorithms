// Hubert Jastrzębski | Satori G17 (Kwarantanna) | 	2022-06-02
// https://satori.tcs.uj.edu.pl/contest/7079339/problems/7664591

#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int z;
    cin >> z;
    while (z--) {
        int n;
        cin >> n;
        vector<vector<int>> G(n);
        for (int i = 0; i < n; i++) {
            int c;
            cin >> c;
            while (c--) {
                int a;
                cin >> a;
                G[a - 1].push_back(i);
            }
        }

        int cnt = 0, sccCnt = 1;
        stack<int> S;
        vector<int> SCC(n);
        vector<int> tin(n, -1), low(n, -1);
        function<void(int)> DFS = [&](int u) {
          tin[u] = low[u] = cnt++;
          S.push(u);
          for (auto& v : G[u]) {
              if (tin[v] == -1) {
                  DFS(v);
                  low[u] = min(low[u], low[v]);
              }
              else if (tin[v] != INT32_MAX)
                  low[u] = min(low[u], tin[v]);
          }

          if (low[u] == tin[u]) {
              int v;
              do {
                  v = S.top(); S.pop();
                  SCC[v] = sccCnt;
                  tin[v] = INT32_MAX;
              } while (u != v);
              sccCnt++;
          }
        };

        for (int u = 0; u < n; u++) {
            if (tin[u] == -1)
                DFS(u);
        }

        //jubert to noobek

        vector<int> Sizes(sccCnt);
        for (auto& scc : SCC) Sizes[scc]++;

        for (int i = 0; i < n; i++) {
            for (auto& v : G[i]) {
                if (SCC[i] != SCC[v])
                    Sizes[SCC[v]] = INT32_MAX;
            }
        }

        int res = min_element(Sizes.begin() + 1, Sizes.end()) - Sizes.begin();
        cout << Sizes[res] << '\n';
        for (int i = 0; i < n; i++)
            if (SCC[i] == res)
                cout << i + 1 << ' ';
        cout << '\n';
    }
}