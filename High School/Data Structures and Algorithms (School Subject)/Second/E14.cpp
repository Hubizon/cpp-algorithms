// Hubert Jastrzębski | Satori E14 (Imperium kontratakuje) | 2021-02-01
// https://satori.tcs.uj.edu.pl/contest/7079339/problems/7097471

#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

constexpr int INF = 2e8;

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
        vector<pair<int, int>> V(n);
        for (auto& [d, t] : V) cin >> d >> t;

        vector<vector<int>> L(2, vector<int>(n)), R(2, vector<int>(n)); // dlugosc, index
        for (int s = 1; s < n; s++) {
            for (int i = 0; i < n - s; i++) {
                L[s % 2][i] = min(L[(s - 1) % 2][i + 1] + V[i + 1].first - V[i].first,
                                  R[(s - 1) % 2][i + 1] + V[i + s].first - V[i].first);
                if (L[s % 2][i] >= V[i].second) L[s % 2][i] = INF;
                R[s % 2][i] = min(R[(s - 1) % 2][i] + V[i + s].first - V[i + s - 1].first,
                                  L[(s - 1) % 2][i] + V[i + s].first - V[i].first);
                if (R[s % 2][i] >= V[i + s].second) R[s % 2][i] = INF;
            }
        }

        int res = min(L[(n - 1) % 2][0], R[(n - 1) % 2][0]);
        if (res >= INF) cout << "FAIL\n";
        else cout << res << '\n';
    }
}