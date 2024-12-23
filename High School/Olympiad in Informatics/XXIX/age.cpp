// Hubert Jastrzębski | XXIX OI II (Agenci) | 2022-02-16
// https://sio2.mimuw.edu.pl/c/oi29-2/p/age/

#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> A(k);
    for (auto& a : A) {
        cin >> a; --a;
    }

    if (k == 1) {
        vector<vector<int>> G(n);
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            G[--a].push_back(--b);
            G[b].push_back(a);
        }

        // część kodu jest z serweru na Discordzie z algorytmami
        int res = 2 * (n - 1);
        int maxPath = 0;

        vector<bool> visited(n);
        function<void(int, int)> DFS = [&](int u, int l) {
          visited[u] = true;
          for (auto v : G[u])
              if (!visited[v])
                  DFS(v, l + 1);
          maxPath = max(maxPath, l);
        };

        DFS(A[0], 0);
        res -= maxPath;
        cout << res;
        return 0;
    }

        // ścieżka
    else {
        vector<vector<int>> G(n);
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            G[--a].push_back(--b);
            G[b].push_back(a);
        }

        vector<int> V(n, -1); // jaki agent znajduje się w tym wierzchołku
        for (int i = 0; i < k; i++) {
            V[A[i]] = i;
        }

        bool isPath = true;
        /*for (int i = 0; i < n - 1; i++) {
            if (G[i].size() > 2)
                isPath = false;
        }*/

        if (isPath) {
            int begin = -1, end = -1;
            for (int i = 0; i < n; i++) {
                if (G[i].size() == 1) {
                    if (begin == -1) begin = i;
                    else end = i;
                }
            }

            int res = (n - 1);
            int minPath = res;

            vector<bool> visited(n);
            function<void(int, int)> lDFS = [&](int u, int l) {
              visited[u] = true;
              if (V[u] != -1) {
                  minPath = min(minPath, l);
                  l = -1;
              }
              for (auto v : G[u])
                  if (!visited[v])
                      lDFS(v, l + 1);
            };

            lDFS(begin, 0);
            visited = vector<bool>(n);
            lDFS(end, 0);
            cout << res + minPath - (k - 1);
            return 0;
        }
    }



    /* else {
        vector<set<int>> GG(n);
        for (int i = 0; i < n; i++) {
            for (auto& g : G[i])
                GG[i].insert(g);
        }

        vector<int> PA(k); // agenci rodzice agentów
        vector<set<int>> CA(k); // agenci dzieci agentów
        vector<bool> visited(n);
        function<void(int, int)> DFS = [&](int u, int p) { // dfsy tak samo
            if (V[u] != -1) {
                V[u] = p;
                CA[p].insert(u);
                p = V[u];
            }
            visited[u] = true;
            for (auto v : G[u])
                if (!visited[v])
                    DFS(v, p);

        };

        DFS(A[0], 0);

        vector<int> P(n, -1); // rodzice wierzchołków
        function<void(int, int)> pDFS = [&](int u, int p) {
            P[u] = p;
            for (auto v : G[u])
                if (P[v] != -1)
                    DFS(v, u);

        };

        pDFS(A[0], A[0]);

        queue<int> Q;
        for (int i = 0; i < k; i++) {
            if (CA[i].empty()) Q.push(i);
        }

        auto resForOne = [&](int w) {
            int nodes = 0;
            int maxPath = 0;

            vector<bool> visited(n);
            function<void(int, int)> resDFS = [&](int u, int l) {
                visited[u] = true;
                nodes++;
                for (auto v : G[u])
                    if (!visited[v])
                        resDFS(v, l + 1);
                maxPath = max(maxPath, l);
            };

            resDFS(w, 0);
            return (2 * (nodes - 1) - maxPath);
        };

        int res = 0;
        while (Q.size()) {
            auto w = Q.front(); Q.pop();
            auto p = PA[w];
            CA[p].erase(w);
            if (CA[p].empty()) Q.push(p);

            vector<int> Path; // wierzchołki leżące na drodze pomiędzy p i w
            function<bool(int, int)> pathDFS = [&](int u, int p) {
                visited[u] = true;
                Path.push_back(u);
                for (auto v : G[u]) {
                    if (v == w)
                        return true;
                    if (v != p)
                        if (pathDFS(v, u)) return true;
                }
                return false;
            };

            pDFS(p, P[p]);
            Path.push_back(w);

            int x, y; // krawedz do usuniecia



            //G[x].erase(y);
            //G[y].erase(x);

            res += resForOne(w);
        }

        res += resForOne(A[0]);

        cout << res;
    }*/

}