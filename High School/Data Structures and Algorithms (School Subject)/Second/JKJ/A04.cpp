// Hubert Jastrzębski | Satori A04 (Liczby parzystocyfrowe) | 2021-05-07
// https://satori.tcs.uj.edu.pl/contest/6941273/problems/6943039

#include <iostream>
#include <string>

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
        unsigned long long n;
        cin >> n;

        long long p = 1, a;

        while (p <= n) p *= 5;
        p /= 5;

        while (p >= 1) {
            a = n / p;
            n %= p;
            p /= 5;
            cout << a * 2;
        }

        /*string result = "";
        if (n == 0)
            cout << n;
        else while (n /= 5)
                result += (n % 5) * 2 + '0';
        cout << string(result.rbegin(), result.rend()} << '\n';*/

        cout << '\n';
    }
}