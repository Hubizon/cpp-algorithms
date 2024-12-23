// Hubert Jastrzębski | Satori F01 (Za siedmioma górami...) | 2022-09-20
// https://satori.tcs.uj.edu.pl/contest/7808974/problems/7813407

#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int z;
    cin >> z;
    while (z--) {
        int n;
        cin >> n;
        vector<vector<pair<int, int>>> G(n);
        for (int i = 0; i < n - 1; i++) {
            int a, b, d;
            cin >> a >> b >> d; --a, --b;
            G[a].push_back({ b, d });
            G[b].push_back({ a, d });
        }

        function<void(vector<int>&, int, int)> DFS = [&](vector<int>& dist, int u, int p) {
          for (auto& [v, w] : G[u]) {
              if (v == p) continue;
              dist[v] = dist[u] + w;
              DFS(dist, v, u);
          }
        };

        vector<int> dist1(n);
        DFS(dist1, 0, 0);

        int a = max_element(dist1.begin(), dist1.end()) - dist1.begin();
        vector<int> dist2(n);
        DFS(dist2, a, a);

        int b = max_element(dist2.begin(), dist2.end()) - dist2.begin();
        vector<int> dist3(n);
        DFS(dist3, b, b);

        for (int i = 0; i < n; i++)
            cout << max(dist2[i], dist3[i]) << ' ';

        cout << '\n';
    }
}