// Hubert Jastrzębski | Satori E13 (Tartak) | 2021-10-08
// https://satori.tcs.uj.edu.pl/contest/7079339/problems/7097451

#include <iostream>
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
    while (z--) {
        int d, n;
        cin >> d >> n;
        vector<ll> V(n + 2);
        V.front() = 0;
        for (int i = 1; i <= n; i++) cin >> V[i];
        V.back() = d;
        sort(V.begin(), V.end());

        vector<vector<ll>> DP(n + 2);
        for (int i = 0; i < n + 2; i++) DP[i].resize(n + 2 - i);
        for (int s = 2; s <= n + 1; s++) {
            for (int i = 0; i <= n + 1 - s; i++) {
                ll x = LLONG_MAX;
                for (ll e = 1; e < s; e++)
                    x = min(x, DP[e][i] + DP[s - e][i + e] + max(V[i + e] - V[i], V[i + s] - V[i + e]));
                DP[s][i] = x;
            }
        }

        cout << DP[n + 1][0] << '\n';
    }
}