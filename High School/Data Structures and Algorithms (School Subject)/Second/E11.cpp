// Hubert Jastrzębski | Satori E11 (Pizza) | 2022-02-04
// https://satori.tcs.uj.edu.pl/contest/7079339/problems/7088835

#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

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
        vector<int> V(n);
        for (auto& v : V) cin >> v;
        int sum = accumulate(V.begin(), V.end(), 0);

        vector<vector<int>> DP(2, vector<int>(n));
        for (int d = 1; d <= n; d++)
            for (int i = 0; i < n; i++)
                DP[d % 2][i] = max(V[i] - DP[(d - 1) % 2][(i + 1) % n],
                                   V[(i + d - 1) % n] - DP[(d - 1) % 2][i]);

        int W = *max_element(DP[n % 2].begin(), DP[n % 2].end());
        cout << (W + sum) / 2 << ' ' << (-W + sum) / 2 << '\n';
    }
}