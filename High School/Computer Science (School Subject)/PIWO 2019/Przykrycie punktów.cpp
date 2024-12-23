// Hubert Jastrzębski | PIWO 2019/2020 (Przykrycie punktów) | 2020-10-11
// https://szkopul.edu.pl/c/piwo-201920/p/ppk/

#include <iostream>

using namespace std;

int main()
{
    int n, max = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        if (x + y > max)
            max = x + y;
    }

    cout << max;

    return 0;
}