// Hubert Jastrzębski | Satori A08 (System dwójkowy) | 2020-09-28
// https://satori.tcs.uj.edu.pl/contest/6459992/problems/6475955

#include <iostream>
#include <string>

using namespace std;

string decimalToBinar(int);

int main()
{
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if(x == 0)
            cout << "0" << endl;
        else
            cout << '1' << decimalToBinar(x) << endl;
    }
}

string decimalToBinar(int x)
{
    string out = "";

    while(x > 1)
    {
        out = to_string(x % 2) + out;
        x /= 2;
    }

    return out;
}