// Hubert Jastrzębski | Satori C01 (Agenci) | 2021-06-12
// https://satori.tcs.uj.edu.pl/contest/6941273/problems/7039452

#include <iostream>

using namespace std;

long long quickPower(long long a, long long k, long long q)
{
    // returns a^k % q
    long long out = 1;
    while (k) {
        if (k & 1) (out *= a) %= q;
        k >>= 1;
        (a *= a) %= q;
    }
    return out;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int z;
    cin >> z;
    while (z--)
    {
        long long n, k;
        cin >> n >> k;
        cout << quickPower(n + 1, k, 1117111) << '\n';
    }
}