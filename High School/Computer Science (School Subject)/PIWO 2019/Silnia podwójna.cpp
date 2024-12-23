// Hubert Jastrzębski | PIWO 2019/2020 (Silnia podwójna) | 2020-10-14
// https://szkopul.edu.pl/c/piwo-201920/p/spd/

#include <iostream>

using namespace std;

int main()
{
    unsigned long long x, out = 1;
    cin >> x;

    if (x == 0)
        out = 0;

    while (x > 1)
    {
        out *= x;
        x -= 2;
    }

    cout << out;

    return 0;
}