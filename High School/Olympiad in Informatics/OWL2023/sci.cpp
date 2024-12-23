// Hubert Jastrzębski | PREOI / OWL 2023 (Ścieżki w drzewie) | 2023-02-05
// https://sio2.staszic.waw.pl/c/preoi-2023/p/sci/

#include <iostream>
#include <functional>
#include <vector>
#include <set>

using namespace std;

typedef long long ll;

constexpr int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> V(n);
    for (auto& v : V)
        cin >> v;

    vector<vector<int>> G(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    ll res = 0;
    for (int s = 0; s < n; s++) {
        vector<bool> vis(n);
        set<int> Path = { V[s] };
        function<void(int)> DFS = [&](int u) {
          vis[u] = true;
          if (s <= u) {
              ll cnt = 1;
              for (auto p : Path) {
                  (res += p * cnt++) %= MOD;
              }
          }
          for (auto& v : G[u]) {
              if (vis[v]) continue;
              Path.insert(V[v]);
              DFS(v);
              Path.erase(V[v]);
          }
        };

        DFS(s);
    }

    cout << res;
}