// Hubert Jastrzębski | PREOI / OWL 2023 (Choinka świąteczna) | 2023-01-31
// https://sio2.staszic.waw.pl/c/preoi-2023/p/cho/

#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <array>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<array<int, 3>>> G(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v, a, b;
        cin >> u >> v >> a >> b;
        --u, --v;
        G[u].push_back({ v, a, b });
        G[v].push_back({ u, a, b });
    }

    vector<int> X(n), Y(n);
    function<void(int, int)> DFS = [&](int u, int p) {
      for (auto& [v, a, b] : G[u]) {
          if (v == p) continue;
          X[v] = X[u] ^ a;
          Y[v] = Y[u] ^ b;
          DFS(v, u);
      }
    };

    DFS(0, -1);

    vector<int> Xcnt(30), Ycnt(30);
    for (int i = 0; i < n; i++) {
        auto x = X[i], y = Y[i];
        for (int j = 0; j < 30; j++) {
            if ((x >> j) & 1)
                Xcnt[j]++;
            if ((y >> j) & 1)
                Ycnt[j]++;
        }
    }

    for (int i = 0; i < 30; i++) {
        if (Xcnt[i] != Ycnt[i] && Xcnt[i] != n - Ycnt[i]) {
            cout << "NIE";
            exit(0);
        }
        else if (Xcnt[i] == n - Ycnt[i])
            X[0] ^= (1 << i);
    }

    DFS(0, -1);

    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());

    cout << (X == Y ? "TAK" : "NIE");
}