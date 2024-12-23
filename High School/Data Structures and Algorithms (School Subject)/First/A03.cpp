// Hubert Jastrzębski | Satori A03 (Prostokąt) | 2020-09-14
// https://satori.tcs.uj.edu.pl/contest/6459992/problems/6463811

#include <iostream>

using namespace std;

int main()
{
    int x, y;
    cin >> y >> x;

    if(y < 1)
        return 0;

    for(int i = 0; i < x; i++)
        cout << "X";
    cout << endl;

    for(int i = 2; i < y; i++)
    {
        cout << "X";

        for(int i = 2; i < x; i++)
            cout << " ";

        cout << "X" << endl;
    }

    if(y > 1)
        for(int i = 0; i < x; i++)
            cout << "X";

    return 0;
}