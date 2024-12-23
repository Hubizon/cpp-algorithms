// Hubert Jastrzębski | XXX OI II (Wspinaczka) | 2023-02-16
// https://sio2.mimuw.edu.pl/c/oi30-2/p/wsp/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void brute(const int n, const int m, const int k) {
    vector<ll> F(n);
    for (auto& f : F)
        cin >> f;

    vector<vector<int>> G(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        G[a].push_back(b);
    }

    for (int p = 0; p < n; p++) {
        vector<bool> vis(n);
        function<void(int)> DFS = [&](int u) {
          if (vis[u]) return;
          vis[u] = true;
          for (auto v : G[u])
              DFS(v);
        };

        DFS(p);
        ll res = 0;
        for (int i = 0; i < n; i++)
            if (vis[i])
                res += F[i];

        cout << res << '\n';
    }
}

void brute2(const int n, const int m, const int k) {
    vector<ll> F(n);
    for (auto& f : F)
        cin >> f;

    vector<vector<int>> G(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        G[a].push_back(b);
    }

    vector<ll> DP(n); DP[n - 1] = F[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        DP[i] = F[i] + DP[G[i][0]];
    }

    for (auto dp : DP)
        cout << dp << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    if (n <= 1000)
        brute(n, m, k);
    else if (m == n - 1)
        brute2(n, m, k);
    else
        brute(n, m, k);
}