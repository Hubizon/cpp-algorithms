// Hubert Jastrzębski | XXIX OI I (Montażysta) | 2021-11-06
// https://sio2.mimuw.edu.pl/c/oi29-1/p/mon/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;
typedef unsigned long long ull;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    // ustawianie w mapie punktów, gdzie mamy mieć zmontowany film i jakie to są filmy
    vector<pair<int, int>> V(n); // input - t, d
    map<int, pair<ull, vector<int>>> F; // sum of t, indexes
    for (int i = 0; i < n; i++) {
        int t, d;
        cin >> t >> d;
        // sprawdzenie czy zmontowanie danego filmu jest w ogóle możliwe
        if (t <= d) {
            V[i] = { t, d };
            F[d].first += t;
            F[d].second.push_back(i);
        }
    }

    // sumy prefixowe
    ull tPre = 0;
    for (auto& [key, value] : F)
        value.first = (tPre += value.first);

    // Rozpatrywanie po kolei każdego deadline'u i sprawdzanie czy jest on poprawny
    priority_queue <pair<int, int>> Films; // t, index
    ull preMinus = 0;
    for (auto& [key, value] : F) {
        auto [sum, films] = value;
        sum -= preMinus;
        for (auto& film : films) Films.push({ V[film].first, film });
        // Jeśli nie, usuwanie z wyniku najdłuższego filmu
        while (sum > key) {
            auto [t, x] = Films.top();
            Films.pop();
            sum -= t;
            preMinus += t;
        }
    }

    // przepisywanie do R filmów które są w wyniku
    vector<pair<int, int>> R; // t, index
    while (!Films.empty()) {
        R.push_back(Films.top());
        Films.pop();
    }

    // sortowanie od najmniejszego deadline'u
    sort(R.begin(), R.end(), [&](auto x, auto y) { return V[x.second].second < V[y.second].second; });
    cout << R.size() << '\n';

    // wypisywanie wyniku
    int day = 1;
    for (auto& [t, i] : R) {
        cout << i + 1 << ' ' << day << '\n';
        day += t;
    }
}