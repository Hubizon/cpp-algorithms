// Hubert Jastrzębski | Satori T01 (Manacher) | 2022-02-21
// https://satori.tcs.uj.edu.pl/contest/7079339/problems/7400357

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio();
    cin.tie(0);

    int z;
    cin >> z;
    while (z--) {
        string W, S = "#";
        cin >> W;

        for (auto& w : W)
            S += w, S += '#';
        S += '#';

        int n = S.size();
        vector<int> R(n);
        R[0] = 1;

        for (int i = 1, j = 1, k; i < n; i += k, j -= k) {
            while (i - j >= 0 && i + j < n && S[i - j] == S[i + j]) j++;
            R[i] = j;
            for (k = 1; k + R[i - k] < j; k++) R[i + k] = R[i - k];
        }

        int q;
        cin >> q;
        while (q--) {
            int a, b;
            cin >> a >> b; --a;
            if (R[a + b] > b - a) cout << "TAK\n";
            else cout << "NIE\n";
        }
    }
}