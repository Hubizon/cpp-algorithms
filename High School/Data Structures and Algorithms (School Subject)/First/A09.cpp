// Hubert Jastrzębski | Satori A09 (Systemy liczbowe) | 2020-09-28
// https://satori.tcs.uj.edu.pl/contest/6459992/problems/6475971

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string cOrD;
        cin >> cOrD;

        if (cOrD == "code")
        {
            int x, b;
            cin >> x >> b;

            string out;
            while (x > 0)
            {
                if (x % b > 9 && b > 9)
                    out = ((char)(x % b - 10 + 'A')) + out;
                else
                    out = to_string(x % b) + out;
                x /= b;
            }
            if (out == "")
                cout << 0 << endl;
            cout << out << endl;
        }
        else
        {
            string x;
            int b;
            cin >> x >> b;

            if (x == "0")
                cout << 0 << endl;
            else
            {
                int out = 0;
                for (int i = 0; i < x.size(); i++)
                    if (x.at(i) - '0' < 10)
                        out = out * b + (x.at(i)) - '0';
                    else
                        out = out * b + ((x.at(i)) - 'A' + 10);
                cout << out << endl;
            }
        }
    }
}