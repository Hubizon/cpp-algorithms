// Hubert Jastrzębski | Satori 1C (Żarówki) | 2021-09-19
// https://satori.tcs.uj.edu.pl/contest/7079785/problems/7080076

#include <iostream>
#include <functional>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int z;
    cin >> z;
    while (z--)
    {
        int n, m;
        cin >> n >> m;
        vector<bool> V(n);
        for (auto&& v : V) {
            int a;
            cin >> a;
            v = a;
        };

        vector<vector<int>> G(n);
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            --a, --b;
            G[a].push_back(b);
            G[b].push_back(a);
        }

        vector<int> SCC(n);
        int sccCnt = 1, onesCnt = 0;
        function<void(int)> sccDFS = [&](int u) {
          for (auto v : G[u]) {
              auto& scc = SCC[v];
              if (scc) continue;
              scc = sccCnt;
              onesCnt += V[v];
              sccDFS(v);
          }
        };

        for (int i = 0; i < n; i++) {
            if (SCC[i]) continue;
            SCC[i] = sccCnt;
            onesCnt += V[i];
            sccDFS(i);
            if (onesCnt % 2) break;
            sccCnt++;
            onesCnt = 0;
        }

        if (onesCnt) cout << "NIE\n";
        else cout << "TAK\n";
    }
}