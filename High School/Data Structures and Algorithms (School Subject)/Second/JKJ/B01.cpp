// Hubert Jastrzębski | Satori B01 (Autobus) | 2021-05-11
// https://satori.tcs.uj.edu.pl/contest/6941273/problems/6953555

#include <iostream>

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
        int k, result = 0;
        cin >> k;

        while(k--)
            result = result * 2 + 1;

        cout << result << '\n';
    }
}