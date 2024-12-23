// Hubert Jastrzębski | Satori P02 (Para najbliższych punktów) | 2023-02-28
// https://satori.tcs.uj.edu.pl/contest/7808974/problems/8125513

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int z;
    cin >> z;
    while (z--) {
        int n;
        cin >> n;
        vector<pair<int, int>> P(n);
        for (auto& [x, y] : P)
            cin >> x >> y;

        sort(P.begin(), P.end());
        ll d2 = 1e9;

        set<pair<int, int>> S;
        S.insert({ -1e9, 1e9 });
        S.insert({ 1e9, 1e9 });

        for (auto [x, y] : P) {
            auto it = S.insert({ y, x }).first;

            auto itup = it;
            while (true) {
                itup++;
                ll yd = itup->first - y;
                if (yd * yd >= d2) break;
                ll xd = x - itup->second;
                if (xd * xd >= d2)
                    itup = S.erase(itup), itup--;
                else
                    d2 = min(d2, xd * xd + yd * yd);//xdxd
            }

            auto itdown = it;
            while (true) {
                itdown--;
                ll yd = y - itdown->first;
                if (yd * yd >= d2) break;
                ll xd = x - itdown->second;
                if (xd * xd >= d2)
                    itdown = S.erase(itdown);
                else
                    d2 = min(d2, xd * xd + yd * yd);//xdxd
            }
        }

        cout << d2 << '\n';
    }
}