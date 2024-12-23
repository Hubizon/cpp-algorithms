// Hubert Jastrzębski | Satori E02 (Ciągi arytmetyczne) | 2021-07-05
// https://satori.tcs.uj.edu.pl/contest/6941273/problems/7059930

#include <iostream>
#include <vector>
#include <climits>

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
        vector<long long> V(n);
        for (auto& v : V) cin >> v;
        if (n <= 1) {
            cout << 1 << '\n';
            continue;
        }
        long long r = V[n - 1] - V[n - 2], i;
        for (i = n - 2; i >= 0; --i)
            if (V[i + 1] - V[i] != r) break;
        cout << i + 2 << '\n';
    }
}