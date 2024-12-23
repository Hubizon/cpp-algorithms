// Hubert Jastrzębski | Satori A14 (Hipoteza Collatza) | 2020-10-12
// https://satori.tcs.uj.edu.pl/contest/6459992/problems/6497167

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;

    cout << n << endl;
    while(n != 1)
    {
        if(n % 2 == 0)
            n /= 2;
        else
            n = n * 3 + 1;

        cout << n << endl;
    }

    return 0;
}