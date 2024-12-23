// Hubert Jastrzębski | Satori A10 (Faktoryzacja) | 2020-10-05
// https://satori.tcs.uj.edu.pl/contest/6459992/problems/6475983

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        bool y = false;
        int x;
        cin >> x;
        cout << x << " = ";


        for(int j = 2; j*j <= x; j++)
        {
            int k = 0;
            while(x % j == 0)
            {
                x /= j;
                k++;
            }
            if(k != 0)
            {
                if(k == 1)
                    if(!y)
                        cout << j;
                    else
                        cout << "*" << j;
                else
                if(!y)
                    cout << j << "^" << k;
                else
                    cout << "*" << j << "^" << k;
                y = true;
            }
        }
        if(x != 1)
            if(y)
                cout << "*" << x;
            else
                cout << x;
        cout << endl;
    }

    return 0;
}