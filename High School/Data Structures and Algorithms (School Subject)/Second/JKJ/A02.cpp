// Hubert Jastrzębski | Satori A02 (Deski) | 2021-05-07
// https://satori.tcs.uj.edu.pl/contest/6941273/problems/6943007

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

        vector<long long> lengths(n);
        for (int i = 0; i < n; i++)
            cin >> lengths[i];

        sort(lengths.begin(), lengths.end(), greater<long long>());

        if (lengths.size() >= 4)
            cout << lengths[3] * lengths[3] << '\n';
        else
            cout << "0\n";
    }
}