// Hubert Jastrzębski | Satori H04 (Smok) | 2022-10-22
// https://satori.tcs.uj.edu.pl/contest/7808974/problems/7986860

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
        int n;
        cin >> n;

        vector<int> V(n);
        for (auto& v : V)
            cin >> v;

        sort(V.rbegin(), V.rend());
        long long res = 0;
        for (int i = 0; i < n; i++)
            res = max(res, res + V[i] - i);

        cout << res << '\n';
    }
}