// Hubert Jastrzębski | Satori E08 (Remont autostrady) | 2021-04-12
// https://satori.tcs.uj.edu.pl/contest/6459992/problems/6835037

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int z;
    cin >> z;
    while (z--)
    {
        long long n, pLength, pPrice;
        cin >> n;
        vector<long long> position(n);
        vector<long long> penalty(n);
        long long tempIndex;
        for (long long i = 0; i < n; i++) {
            cin >> tempIndex;
            position[i] = tempIndex - 1;
            cin >> penalty[i];
        }
        cin >> pLength >> pPrice;

        vector<long long> minCost(n + 1);
        long long k = 0;
        for (long long i = 1; i <= n; i++) {
            //k = *lower_bound(position.begin(), position.end(), position[i - 1] - pLength );
            while (position[k] < position[i - 1] - pLength) k++;
            minCost[i] = min(minCost[i - 1] + penalty[i - 1], pPrice + minCost[k]);
        }

        cout << minCost[n] << '\n';
    }
}