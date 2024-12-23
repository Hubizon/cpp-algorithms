// Hubert Jastrzębski | PREOI / OWL 2023 (Domek na drzewie) | 2023-01-30
// https://sio2.staszic.waw.pl/c/preoi-2023/p/dnd/

#include <iostream>
#include <functional>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;

    vector<bool> A(n);
    for (auto&& a : A) {
        int x;
        cin >> x;
        a = x;
    }

    vector<vector<int>> G(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<int> P(n, -1), F(n);
    function<void(int, int)> DFS = [&](int u, int p) {
      P[u] = p;
      if (A[u]) F[u]++;
      for (auto& v : G[u]) {
          if (v != p) {
              if (A[v]) F[u]++;
              if (A[u]) F[v]++;
              DFS(v, u);
          }
      }
    };

    vector<map<int, int, greater<int>>> V(n);
    function<void(int)> DFS2 = [&](int u) {
      V[u][F[u]]++;
      for (auto& v : G[u]) {
          if (v != P[u]) {
              V[v] = V[u];
              DFS2(v);
          }
      }
    };

    DFS(0, -1);
    DFS2(0);

    int q;
    cin >> q;
    while (q--) {
        ll x, t, k;
        cin >> x >> t >> k;

        auto& M = V[--x];
        ll f = 0;
        for (auto& [val, cnt] : M) {
            t -= cnt;
            if (t <= 0) {
                f = val;
                break;
            }
        }

        if (f == 0)
            cout << "-1\n";
        else
            cout << ((ll)ceil((sqrt(1 + 8.0 * k / f) - 1) / 2)) << '\n';
    }
}