// Hubert Jastrzębski | XXIX OI I (Domino) | 2021-11-21
// https://sio2.mimuw.edu.pl/c/oi29-1/p/dom/

#include <iostream>
#include <climits>
#include <vector>

using namespace std;

typedef unsigned long long ull;
constexpr ull FIBMAX = 1e18 + 1;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Generowanie ciągu Fibonacciego:
    vector<ull> Fb = { 1, 1 };
    for (int i = 0; Fb.back() < FIBMAX; i++)
        Fb.push_back(Fb[i] + Fb[i + 1]);

    ull m;
    cin >> m;

    // Sprawdzanie warunku brzegowego:
    if (m == 1) {
        cout << 1;
        return 0;
    }

    // Tworzę tablicę dzielników należących do ciągu Fibonacciego:
    vector<pair<ull, int>> Div; // divider, sum of indexes
    for (int i = Fb.size() - 1; i > 1; i--) {
        ull x = Fb[i];
        int sum = i;
        while (m % x == 0) {
            Div.push_back({ x, sum });
            if (x > m / x) break;
            x *= x;
            sum = 2 * sum + 1;
        }
    }

    // Maską bitową rozpatruje wszystkie kombinacje dzielników:
    int res = INT_MAX;
    for (int bitm = 1; bitm < (1 << Div.size()); bitm++) {
        ull x = m;
        int tRes = -1;
        for (int i = 0; i < Div.size(); i++) {
            if ((bitm >> i) & 1) {
                if (x % Div[i].first != 0) break;
                x /= Div[i].first;
                tRes += Div[i].second + 1;
            }
        }
        if (x == 1 && tRes < res) res = tRes;
    }

    // Jeśli była poprawna kombinacja, wypisujemy jej wynik:
    if (res == INT_MAX) cout << "NIE";
    else cout << res;
}