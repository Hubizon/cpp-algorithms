// Hubert Jastrzębski | PIWO 2019/2020 (Dziwne sumy) | 2020-10-14
// https://szkopul.edu.pl/c/piwo-201920/p/dzi/

#include <iostream>

using namespace std;

int main()
{
    long long n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        long long x, out = -1, nextPow = 1;
        cin >> x;
        out = (x * (x + 1)) / 2;

        while (nextPow <= x)
        {
            nextPow *= 2;
            out -= nextPow;
        }

        cout << out << endl;
    }

    return 0;
}