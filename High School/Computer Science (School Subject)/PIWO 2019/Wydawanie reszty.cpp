// Hubert Jastrzębski | PIWO 2019/2020 (Wydawanie reszty) | 2020-10-11
// https://szkopul.edu.pl/c/piwo-201920/p/wyd/

#include <iostream>

using namespace std;

int main()
{
    int n, r;
    cin >> n >> r;

    int amount = r / n;

    if (amount * n != r)
        amount++;

    cout << amount;

    return 0;
}