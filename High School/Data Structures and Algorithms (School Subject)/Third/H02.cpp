// Hubert Jastrzębski | Satori H02 (Czekolada) | 2022-10-19
// https://satori.tcs.uj.edu.pl/contest/7808974/problems/7956510

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int z;
    cin >> z;
    while (z--) {
        int m, n;
        cin >> m >> n;

        vector<pair<int, bool>> V(m + n - 2);
        for (int i = 0; i < m - 1; i++) {
            auto& [v, t] = V[i];
            cin >> v;
        }
        for (int i = m - 1; i < V.size(); i++) {
            auto& [v, t] = V[i];
            cin >> v;
            t = true;
        }

        sort(V.rbegin(), V.rend());

        int x = 1, y = 1;
        long long res = 0;
        for (auto& [v, t] : V) {
            if (t) {
                res += v * x;
                y++;
            }
            else {
                res += v * y;
                x++;
            }
        }

        cout << res << '\n';
    }
}