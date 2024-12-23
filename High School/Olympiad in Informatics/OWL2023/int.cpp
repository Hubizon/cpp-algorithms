// Hubert Jastrzębski | PREOI / OWL 2023 (Internet) | 2023-02-02
// https://sio2.staszic.waw.pl/c/preoi-2023/p/int/

#include <iostream>
#include <functional>
#include <vector>
#include <array>
#include <stack>

using namespace std;

void brute(int n, int m) {
    vector<array<int, 3>> E(m);
    for (auto& [a, b, active] : E) {
        cin >> a >> b;
        --a, --b;
    }

    int k;
    cin >> k;
    while (k--) {
        int x;
        cin >> x;
        E[--x][2] = 1;

        vector<vector<int>> G(n), RG(n);
        for (auto [a, b, nactive] : E) {
            if (nactive == 1) continue;
            G[a].push_back(b);
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
        vector<int> SCC(n); // wynik - tablica z numerem scc dla każdego wierzchołka
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

        vector<int> R(scccnt, 1);
        for (auto [a, b, nactive] : E) {
            if (nactive == 1) continue;
            if (SCC[a] != SCC[b])
                R[SCC[b]] = 0;
        }

        int res = -1;
        for (auto& r : R)
            res += r;

        cout << res << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    if (n <= 2000 && m <= 2000) {
        brute(n, m);
        exit(0);
    }

    vector<vector<int>> G(n);
    vector<array<int, 2>> E(m);
    vector<int> IN(n);
    for (auto& [a, b] : E) {
        cin >> a >> b;
        --a, --b;
        G[a].push_back(b);
        G[b].push_back(a);
        IN[b]++;
    }

    vector<int> CC(n, -1);
    int ccCnt = 0;
    function<void(int)> DFS = [&](int u) {
      CC[u] = ccCnt;
      for (auto& v : G[u]) {
          if (CC[v] == -1)
              DFS(v);
      }
    };

    for (int i = 0; i < n; i++) {
        if (CC[i] == -1) {
            DFS(i);
            ccCnt++;
        }
    }

    vector<int> ccRes(ccCnt);
    for (int i = 0; i < n; i++) {
        if (IN[i] == 0)
            ccRes[CC[i]]++;
    }

    int res = 0, ccCycleCnt = 0;
    vector<int> ccCycle(ccCnt, -1);
    for (int i = 0; i < ccCnt; i++) {
        if (ccRes[i] == 0)
            ccCycle[i] = ccCycleCnt++;
        res += max(1, ccRes[i]);
    }

    vector<int> Cycle(n, -1);
    vector<vector<int>> Cycles(ccCycleCnt);
    for (int i = 0; i < n; i++) {
        if (ccCycle[CC[i]] != -1) {
            Cycle[i] = ccCycle[CC[i]];
            Cycles[Cycle[i]].push_back(i);
        }
    }

    int k;
    cin >> k;
    while (k--) {
        int x;
        cin >> x;
        --x;
        if (--IN[E[x][1]] == 0) {
            auto c = Cycle[E[x][1]];
            if (c == -1)
                res++;
            else {
                for (auto& u : Cycles[c])
                    Cycle[u] = -1;
            }
        }
        cout << res << '\n';
    }
}