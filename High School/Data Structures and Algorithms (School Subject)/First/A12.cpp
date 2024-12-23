// Hubert Jastrzębski | Satori A12 (Patyczki) | 2020-10-12
// https://satori.tcs.uj.edu.pl/contest/6459992/problems/6497107

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    int out = 0;

    for(int i = 0; i < 3; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        out += (a + b > c && b + c > a && c + a > b);
    }

    cout << out;

    return 0;
}