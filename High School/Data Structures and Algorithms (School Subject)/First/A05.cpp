// Hubert Jastrzębski | Satori A05 (Rzecz o segmentolkach) | 2020-09-21
// https://satori.tcs.uj.edu.pl/contest/6459992/problems/6469285

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int sn;
        cin >> sn;

        int mdn = sn - 1;
        for(int j = 0; j < sn; j++)
        {
            int x;
            cin >> x;
            mdn += x;
        }
        cout << mdn << "\n";
    }

    return 0;
}