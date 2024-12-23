// Hubert Jastrzębski | Diamentowy Indeks AGH 2020/2021 III (The OR Game) | 2023-03-16
// https://www.diament.agh.edu.pl/wp-content/uploads/2023/08/informatyka_III_2020_2021.pdf

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n, g;
    cin >> n >> g;

    vector<int> T(n);
    for (auto& t : T) cin >> t;

    auto fun = [&]() {
        vector<int> V(n);
        for (int bitmask = 0; bitmask < (1 << n); bitmask++) {
            int tg = 0;
            for (int i = 0; i < n; i++)
                if ((bitmask >> i) & 1)
                    tg ^= T[i];
            if (tg == g) {
                for (int i = 0; i < n; i++)
                    if ((bitmask >> i) & 1)
                        V[i]++;
            }
        }
        return V;
    };

    int res = 0;
    do {
        vector<int> V = fun();
        if (V == vector<int>(V.size())) 
            break;

        auto x = max_element(V.begin(), V.end()) - V.begin();
        vector<int> NT;
        for (int i = 0; i < n; i++)
            if (i != x)
                NT.push_back(T[i]);
        T = NT;
        n = T.size();
        res++;
    } while (true);

    cout << res;
}
