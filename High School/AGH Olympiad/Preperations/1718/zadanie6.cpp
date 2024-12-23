// Hubert Jastrzębski | Diamentowy Indeks AGH 2017/2018 I (Zadanie 6) | 2023-03-04
// https://www.diament.agh.edu.pl/wp-content/uploads/2023/08/matematyka_i_2017_2018.pdf

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

void solve() {
    int n;
    cin >> n;

    vector<ll> V(n);
    for (auto& v : V)
        cin >> v;

    for (int bitmask = 0; bitmask < (1 << n); bitmask++) {
        ll tres = 0;
        for (int i = 0; i < n; i++)
            if ((bitmask >> i) & 1)
                tres += V[i];
        V.push_back(tres);
    }
    
    sort(V.begin(), V.end());

    ll res = V.back() + 1;
    for (int i = 1; i < V.size(); i++) {
        if (V[i] - V[i - 1] > 1) {
            res = V[i - 1] + 1;
            break;
        }
    }

    cout << res;
}

int main()
{
    solve();
}

