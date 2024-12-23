// Hubert Jastrzębski | Krajowe Warsztaty Algorytmiczne PREOI KWA 2022 (Piekielne wiersze) | 2022-02-07
// https://sio2.staszic.waw.pl/c/kwa-2022/p/pie/

#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

constexpr int MAX = 1010;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> G(MAX), RG(MAX);
    vector<int> diff(MAX);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        RG[b].push_back(a);
        diff[b]++, diff[a]--;
    }

    stack<int> R;
    vector<int> vis(MAX);
    for (int m = 0; m < MAX; m++) {
        if (G[m].size() == 0 || vis[m]) continue;

        queue<int> Pos, Neg;
        vector<bool> visited(MAX);
        function<void(int)> qDFS = [&](int u) {
          visited[u] = true;
          for (auto v : G[u])
              if (!visited[v])
                  qDFS(v);
          for (auto v : RG[u])
              if (!visited[v])
                  qDFS(v);
        };

        qDFS(m);
        for (int i = 0; i < MAX; i++) {
            if (!visited[i]) continue;
            if (diff[i] > 0) Pos.push(i);
            if (diff[i] < 0) Neg.push(i);
        }

        while (Pos.size() && Neg.size()) {
            if (Pos.size() == 1 && Neg.size() == 1
                && diff[Pos.front()] == 1 && diff[Neg.front()] == -1) break;
            auto pos = Pos.front(); Pos.pop();
            auto neg = Neg.front(); Neg.pop();
            G[pos].push_back(neg);
            if (--diff[pos] != 0) Pos.push(pos);
            if (++diff[neg] != 0) Neg.push(neg);
        }

        int u = m, v = G[m].front();
        if (Pos.size() && Neg.size())
            u = Neg.front(), v = Pos.front();

        function<void(int)> DFS = [&](int u) {
          vis[u] = true;
          while (!G[u].empty()) {
              auto& v = G[u].back();
              G[u].pop_back();
              DFS(v);
          }
          R.push(u);
        };

        DFS(u);
    }

    cout << R.size() << '\n';
    while (!R.empty()) {
        cout << R.top() << ' ';
        R.pop();
    }
}