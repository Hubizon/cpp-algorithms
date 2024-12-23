// Hubert Jastrzębski | Satori G13 (Euro 2102) | 2022-04-10
// https://satori.tcs.uj.edu.pl/contest/7079339/problems/7358676

#include <iostream>
#include <functional>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int z;
    cin >> z;
    while (z--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> G(n), RG(n);
        while (m--) {
            int a, b;
            cin >> a >> b;
            G[--a].push_back(--b);
            RG[b].push_back(a);
        }

        vector<bool> visited(n);
        stack<int> S;

        function<void(int)> FOrder = [&](int u) {
          if (visited[u]) return;
          visited[u] = true;
          for (auto v : G[u])
              FOrder(v);
          S.push(u);
        };

        for (int i = 0; i < n; i++)
            FOrder(i);

        int scccnt = 1;
        vector<int> SCC(n);
        function<void(int)> rDFS = [&](int u) {
          if (SCC[u]) return;
          SCC[u] = scccnt;
          for (auto& v : RG[u])
              rDFS(v);
        };

        while (!S.empty()) {
            if (!SCC[S.top()]) {
                rDFS(S.top());
                scccnt++;
            }
            S.pop();
        }

        int k;
        cin >> k;
        while (k--) {
            int a, b;
            cin >> a >> b;
            --a, --b;
            cout << (SCC[a] == SCC[b] ? "TAK\n" : "NIE\n");
        }
    }
}