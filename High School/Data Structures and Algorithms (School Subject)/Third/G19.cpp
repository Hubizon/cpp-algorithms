// Hubert Jastrzębski | Satori G19 (2-SAT) | 2022-12-19
// https://satori.tcs.uj.edu.pl/contest/7808974/problems/8125181

#include <iostream>
#include <functional>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int z;
    cin >> z;
    while (z--) {
        int n, m;
        cin >> n >> m;
        int nn = 2 * n;

        vector<vector<int>> G(nn), RG(nn);
        for (int i = 0; i < m; i++) {
            char ca, cb;
            int a, b;
            cin >> ca >> a >> cb >> b;
            ((--a) *= 2) += (ca == '+');
            ((--b) *= 2) += (cb == '+');

            G[a].push_back(b ^ 1);
            G[b].push_back(a ^ 1);

            RG[b ^ 1].push_back(a);
            RG[a ^ 1].push_back(b);
        }

        vector<bool> vis(nn);
        stack<int> S;

        function<void(int)> DFS = [&](int u) {
          vis[u] = true;
          for (auto& v : G[u])
              if (!vis[v])
                  DFS(v);
          S.push(u);
        };

        for (int u = 0; u < nn; u++)
            if (!vis[u])
                DFS(u);

        vector<int> scc(nn, -1);
        int c = 0;

        function<void(int)> rDFS = [&](int u) {
          scc[u] = c;
          for (auto& v : RG[u])
              if (scc[v] == -1)
                  rDFS(v);
        };

        while (S.size()) {
            auto v = S.top(); S.pop();
            if (scc[v] == -1)
                rDFS(v), c++;
        }

        vector<bool> R;
        for (int i = 0; i < nn; i += 2) {
            if (scc[i] == scc[i + 1]) {
                R.clear();
                break;
            }
            else
                R.push_back(scc[i] > scc[i + 1]);
        }

        if (R.empty())
            cout << "NIE";
        else {
            cout << "TAK\n";
            for (auto&& r : R)
                cout << r << ' ';
        }

        cout << '\n';
    }
}