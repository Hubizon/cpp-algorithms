// Hubert Jastrzębski | PREOI / OWL 2023 (Slalom) | 2023-02-02
// https://sio2.staszic.waw.pl/c/preoi-2023/p/sla/

#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <array>

using namespace std;

typedef long long ll;

constexpr ll INF = 1e18;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<array<int, 3>>> G(n);
    for (int i = 0; i < m; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        --a, --b;
        G[a].push_back({ b, c, d });
    }

    vector<int> TS = { n - 1 };
    vector<bool> vis(n); vis[n - 1] = true;
    function<void(int)> TSort = [&](int u) {
      if (vis[u]) return;
      vis[u] = true;
      for (auto [v, c, d] : G[u])
          TSort(v);
      TS.push_back(u);
    };

    for (int u = 0; u < n; u++)
        TSort(u);
    reverse(TS.begin(), TS.end());
    vector<int> TSPos(n);
    for (int i = 0; i < n; i++)
        TSPos[TS[i]] = i;

    vector<vector<ll>> DP(n, vector<ll>(n, INF)); DP[0][0] = 0;
    for (auto x : TS) {
        vector<int> xNeig(n);
        for (auto& [z, c, d] : G[x])
            xNeig[z] = c;
        for (auto y : TS) {
            if (x == y)
                for (auto& [z, c, d] : G[x])
                    DP[z][z] = min(DP[z][z], DP[x][y] + c + d);
            else
                for (auto& [z, c, d] : G[y])
                    if (xNeig[z])
                        DP[z][z] = min(DP[z][z], DP[x][y] + xNeig[z] + c);
            for (auto& [z, c, d] : G[x])
                if (TSPos[z] > TSPos[y])
                    DP[z][y] = min(DP[z][y], DP[x][y] + c);
            for (auto& [z, c, d] : G[y])
                if (TSPos[z] > TSPos[x])
                    DP[x][z] = min(DP[x][z], DP[x][y] + c);
        }
    }

    cout << DP[n - 1][n - 1];
}