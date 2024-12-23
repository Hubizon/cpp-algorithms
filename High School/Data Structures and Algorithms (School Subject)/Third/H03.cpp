// Hubert Jastrzębski | Satori H03 (Ławka) | 2022-10-14
// https://satori.tcs.uj.edu.pl/contest/7808974/problems/7956530

#include <iostream>
#include <algorithm>
#include <vector>
#include <array>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int z;
    cin >> z;
    while (z--) {
        int n;
        cin >> n;

        vector<array<int, 3>> V;
        vector<int> X(n);
        for (int i = 0; i < n; i++) {
            int l, r, x;
            cin >> l >> r >> x;
            X[i] = x;
            V.push_back({ l, 0, i });
            V.push_back({ r, 1, i });
        }

        int p = 0;
        vector<int> B(n);
        sort(V.begin(), V.end());
        for (auto& [a, t, i] : V) {
            if (t == 0) B[i] = p;
            else {
                int pmade = p - B[i];
                if (X[i] > pmade)
                    p += X[i] - pmade;
            }
        }

        cout << p << '\n';
    }
}