// Hubert Jastrzębski | Satori E12 (Triangulacja) | 2021-09-23
// https://satori.tcs.uj.edu.pl/contest/7079339/problems/7088855

#include <iostream>
#include <functional>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int z;
    cin >> z;
    while (z--)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> V(n);
        for (auto& [a, b] : V) cin >> a >> b;

        auto dist = [&](const int i, const int j) {
          ll x = 1LL * V[i].first - V[j].first;
          ll y = 1LL * V[i].second - V[j].second;
          return x * x + y * y;
        };

        vector<vector<pair<ll, ll>>> DP(n, vector<pair<ll, ll>>(n));
        for (int d = 2; d < n; d++) {
            for (int i = 0; i < n; i++) {
                auto& dp = DP[d][i];
                dp = { LLONG_MAX, -1 };
                for (int e = 1; e < d; e++) {
                    if (DP[e][i].first != LLONG_MAX)
                        dp = min(dp, { DP[e][i].first + DP[d - e][(i + e) % n].first, e });
                }
                dp.first += dist(i, (i + d) % n);
            }
        }

        cout << DP[n - 1][0].first - dist(0, n - 1) << ' ';

        function<void(int, int)> f = [&](const int d, const int i) {
          if (d == 1) return;
          auto e = DP[d][i].second;
          if (d != n - 1) cout << i << ' ' << (i + d) % n << ' ';
          f(e, i), f(d - e, (i + e) % n);
        };

        f(n - 1, 0);
        cout << '\n';
    }
}