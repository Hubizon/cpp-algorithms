// Hubert Jastrzębski | Satori C03 (Zakaz rozbijania atomów!) | 2021-06-12
// https://satori.tcs.uj.edu.pl/contest/6941273/problems/7039496

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int z, n;
    cin >> z;
    while (z--)
    {
        cin >> n;
        cout << "AB"[n % 2] << '\n';
    }
}