// Hubert Jastrzębski | Satori E07 (Chorąży) | 2021-04-12
// https://satori.tcs.uj.edu.pl/contest/6459992/problems/6835009

#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    int z;
    cin >> z;
    while (z--)
    {
        int n;
        cin >> n;
        vector<int> H(n);
        for (int& h : H)
            cin >> h;

        vector<int> Lis(n + 1, INT_MAX);
        Lis[0] = INT_MIN;
        Lis[1] = H[0];
        int i = 1, k = 0;
        for (i = 2; i <= n; i++)
            *lower_bound(Lis.begin(), Lis.end(), H[i - 1]) = H[i - 1];

        cout << n - (lower_bound(Lis.begin(), Lis.end(), INT_MAX) - Lis.begin() - 1) << '\n';
    }
}