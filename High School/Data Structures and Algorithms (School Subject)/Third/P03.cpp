// Hubert Jastrzębski | Satori P03 (Gazociągi) | 2023-02-21
// https://satori.tcs.uj.edu.pl/contest/7808974/problems/8242710

#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int z;
    cin >> z;
    while (z--) {
        int n;
        cin >> n;

        vector<pair<int, int>> A(n), B(n);
        long long res = 0;
        for (auto& [ax, ay] : A) {
            cin >> ax >> ay;
            res += ay - ax;
        }

        for (auto& [bx, by] : B) {
            cin >> bx >> by;
            res += bx - by;
        }

        cout << res << '\n';

        vector<array<int, 3>> E; // x, type, id
        for (int i = 0; i < n; i++) {
            E.push_back({ A[i].first, 0, i });
            E.push_back({ B[i].first, 1, i });
        }

        sort(E.begin(), E.end());
        set<pair<int, int>> S;
        for (auto [x, t, id] : E) {
            if (t == 0)
                S.insert({ A[id].second, id });
            else {
                int y = B[id].second;
                auto a = S.lower_bound({ y, -1 });
                cout << a->second + 1 << ' ' << id + 1 << '\n';
                S.erase(a);
            }
        }
    }
}