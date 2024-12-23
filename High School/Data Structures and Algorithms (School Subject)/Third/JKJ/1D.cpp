// Hubert Jastrzębski | Satori 1D (Oscypki) | 2021-09-19
// https://satori.tcs.uj.edu.pl/contest/7079785/problems/7080092

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
    while (z--)
    {
        int n;
        cin >> n;
        vector<int> V(n + 3);
        for (int i = 3; i < V.size(); i++)
            cin >> V[i];

        vector<long long> DP(n + 3);
        for (int i = 3; i < DP.size(); i++)
            DP[i] = max(DP[i - 2], DP[i - 3] + min(V[i - 1], V[i - 2])) + V[i];

        cout << max(DP.back(), *++DP.rbegin()) << '\n';
    }
}