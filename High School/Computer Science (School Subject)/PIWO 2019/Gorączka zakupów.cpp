// Hubert Jastrzębski | PIWO 2019/2020 (Gorączka zakupów) | 2020-10-08
// https://szkopul.edu.pl/c/piwo-201920/p/gor/

#include <iostream>

using namespace std;

int main()
{
    short n;
    cin >> n;

    for (short i = 0; i < n; i++)
    {
        unsigned long long s, a, b, c;
        cin >> s >> a >> b >> c;

        if (s / c >= a)
            cout << (s / c + ((s / c) / a) * b) << endl;
        else
            cout << s / c << endl;
    }

    return 0;
}