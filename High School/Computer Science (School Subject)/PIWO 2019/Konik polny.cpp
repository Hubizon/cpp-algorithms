// Hubert Jastrzębski | PIWO 2019/2020 (Konik polny) | 2020-10-13
// https://szkopul.edu.pl/c/piwo-201920/p/kon/

#include <iostream>

using namespace std;

int main()
{
    int l, s, jumpsAmount = 0;
    cin >> l >> s;

    while (l > 0)
    {
        jumpsAmount++;
        l -= s;
        if (s != 1)
            s /= 2;
    }

    cout << jumpsAmount;

    return 0;
}