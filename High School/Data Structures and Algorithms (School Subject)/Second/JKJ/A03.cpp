// Hubert Jastrzębski | Satori A03 (Szybka informacja) | 	2021-05-07
// https://satori.tcs.uj.edu.pl/contest/6941273/problems/6943027

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int z;
    cin >> z;

    while (z--)
    {
        int n, m;
        cin >> n >> m; // n - liczba kartek, m - liczba gosci

        vector<int> v(n + 1); // numery eksponatow na kartkach (od szczytu do spodu)
        for (int i = 0, a; i < n; i++) {
            cin >> a;
            v[a] = i;
        }

        int a, b, p = 0;
        while (m--) {
            cin >> a;
            b = v[a];
            cout << (b - p + n) % n << ' ';
            p = b;
        }

        cout << '\n';
    }
}