// Hubert Jastrzębski | PIWO 2019/2020 (Login dla każdego) | 2020-10-05
// https://szkopul.edu.pl/c/piwo-201920/p/log/

#include <iostream>

using namespace std;

int main()
{
    string imie, nazwisko;
    cin >> imie >> nazwisko;

    cout << imie[0];
    for(int i = 1; imie[i] < nazwisko[0]; i++)
    {
        if(imie.length() <= i)
            break;
        cout << imie[i];
    }

    cout << nazwisko[0];

    return 0;
}