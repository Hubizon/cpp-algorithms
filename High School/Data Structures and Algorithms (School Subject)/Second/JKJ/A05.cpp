// Hubert Jastrzębski | Satori A05 (Kwadraty) | 2021-05-07
// https://satori.tcs.uj.edu.pl/contest/6941273/problems/6943055

#include <iostream>
#include <vector>
#include <math.h>

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
        long long n;
        cin >> n;

        vector<pair<long long, long long>> result;

        long long i = 1, j = 1, sum = 0;

        while (i * i <= n) {
            if (sum > n)
                sum -= i * i, i++;
            else if (sum < n)
                sum += j * j, j++;
            else {
                result.push_back(make_pair(i, j));
                sum -= i * i, i++;
            }
        }

        cout << result.size() << '\n';
        for (pair<long long, long long>& r : result) {
            cout << r.second - r.first;
            for (long long k = r.first; k < r.second; k++)
                cout << ' ' << k;
            cout << '\n';
        }
    }
}