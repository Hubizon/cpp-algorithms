// Hubert Jastrzębski | Satori E02 (Mosiężny Most) | 2021-03-08
// https://satori.tcs.uj.edu.pl/contest/6459992/problems/6740466

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int a;
    cin >> a;
    while (a--)
    {
        int n;
        cin >> n;
        vector<int> V(n + 1, 0);
        for (int i = 1; i <= n; i++)
            cin >> V[i];

        if (n <= 0) {
            cout << "0\n";
            continue;
        }
        else if (n == 1) {
            cout << V[1] << '\n';
            continue;
        }
        else if (n == 2) {
            cout << V[1] + V[2] << '\n';
            continue;
        }

        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = V[1];
        dp[2] = V[1] + V[2];
        for (int i = 3; i < n + 1; i++)
            dp[i] = max({ dp[i - 1], dp[i - 2] + V[i], dp[i - 3] + V[i] + V[i - 1] });
        cout << dp[n] << '\n';
    }
}