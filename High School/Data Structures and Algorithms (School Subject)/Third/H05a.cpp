// Hubert Jastrzębski | Satori H05 (Rakieta) | 2022-10-27
// https://satori.tcs.uj.edu.pl/contest/7808974/problems/8008063

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

constexpr int INF = 1e9;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int z;
    cin >> z;
    while (z--) {
        int n;
        cin >> n;

        vector<pair<int, int>> V(n);
        for (auto& [m, w] : V)
            cin >> m >> w;

        sort(V.begin(), V.end(), [&](auto& lhs, auto& rhs)
        { return lhs.first + lhs.second < rhs.first + rhs.second; });

        vector<vector<int>> dp(n + 1, vector<int>(n));
        for (int h = 1; h <= n; h++) {
            dp[h][0] = INF;
            if (h == 1) dp[h][0] = V[0].first;
            for (int i = 1; i < n; i++) {
                dp[h][i] = dp[h][i - 1];
                if (dp[h - 1][i - 1] <= V[i].second)
                    dp[h][i] = min(dp[h][i], dp[h - 1][i - 1] + V[i].first);
            }
        }

        int res = 0;
        for (int h = 1; h <= n; h++) {
            for (int i = 0; i < n; i++) {
                if (dp[h][i] < INF)
                    res = h;
            }
        }

        cout << res << '\n';
    }
}