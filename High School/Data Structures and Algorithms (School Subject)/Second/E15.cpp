// Hubert Jastrzębski | Satori E15 (Muszkieterowie) | 2021-10-22
// https://satori.tcs.uj.edu.pl/contest/7079339/problems/7151442

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int z;
    cin >> z;
    while (z--) {
        int n;
        cin >> n;
        vector<vector<bool>> V(n, vector<bool>(n));
        for (auto& v : V) {
            for (auto&& vv : v) {
                char a;
                cin >> a;
                vv = a - '0';
            }
        }

        // DP[d][i] - czy na przedziale od i o długoci d da się tak zorganizować walki, żeby muszkieter i, i + d walczyli razem (chyba)
        vector<vector<bool>> DP(n + 1, vector<bool>(n, false));
        DP[1] = vector<bool>(n, true);
        for (int d = 2; d <= n; d++) {
            for (int i = 0; i < n; i++) {
                for (int e = 1; e < d; e++) {
                    if (DP[e][i] && DP[d - e][(i + e) % n] && (V[i][(i + e) % n] || V[(i + d) % n][(i + e) % n])) {
                        DP[d][i] = true;
                        break;
                    }
                }
            }
        }

        vector<int> R;
        for (int i = 0; i < n; i++)
            if (DP[n][i]) R.push_back(i + 1);

        cout << R.size() << '\n';
        sort(R.begin(), R.end());
        for (auto r : R) cout << r << '\n';
    }
}