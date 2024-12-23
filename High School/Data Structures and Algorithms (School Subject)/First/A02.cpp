// Hubert Jastrzębski | Satori A02 (Odwróć liczby) | 2020-09-14
// https://satori.tcs.uj.edu.pl/contest/6459992/problems/6463771

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int liczby[n];

    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        liczby[i] = x;
    }

    for(int i = (n-1); i >= 0; i--)
        cout << liczby[i];

    return 0;
}