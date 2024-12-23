// Hubert Jastrzębski | PIWO 2019/2020 (Włamanie do galerii) | 2020-10-11
// https://szkopul.edu.pl/c/piwo-201920/p/wla/

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int min = 0, max = 0;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (min > x || min == 0)
            min = x;
        if (max < x)
            max = x;
    }

    cout << (max - min - 1) - (n - 2);

    return 0;
}