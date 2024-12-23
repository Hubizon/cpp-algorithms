// Hubert Jastrzębski | Satori A01 (Serca) | 2021-05-07
// https://satori.tcs.uj.edu.pl/contest/6941273/problems/6942995

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    const string LINES[] = { "     @     ", "    @ @    ", "   @   @   ", "  @     @  ", " @       @ ", "@         @", "@    @    @", "@   @ @   @", " @@@   @@@ " };

    for (int i = 9; i--;) {
        for (int j = n; j--;)
            cout << LINES[i] << ' ';
        cout << '\n';
    }
}