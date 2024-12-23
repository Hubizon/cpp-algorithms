// Hubert Jastrzębski | Krajowe Warsztaty Algorytmiczne PREOI KWA 2022 (Porządek alfabetyczny) | 2022-02-09
// https://sio2.staszic.waw.pl/c/kwa-2022/p/alf/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, l;
    cin >> n >> l;

    vector<string> V(n);
    for (auto& v : V) cin >> v;

    vector<vector<int>> C(n - 1, vector<int>(l + 1)); // 1 - zielone, 2 - czerwone
    for (int i = 0; i < n - 1; i++) {
        for (int j = l - 1; j >= 0; j--) {
            if (V[i][j] < V[i + 1][j]) C[i][j] = 1;
            else if (V[i][j] > V[i + 1][j]) C[i][j] = 2;
            else if (C[i][j + 1] == 2) C[i][j] = 2;
        }
    }

    vector<int> Gs(n - 1);
    int zcnt = n - 1;
    pair<int, int> res = { l, 0 };
    int p = 0, q = 1;
    for (int i = 0; i < n - 1; i++) {
        if (C[i][0] == 1)
            if (++Gs[i] > 0) zcnt--;
    }

    while (p != l) {
        while (zcnt && q != l) {
            for (int i = 0; i < n - 1; i++) {
                if (C[i][q] == 1)
                    if (Gs[i]++ == 0) zcnt--;
            }
            q++;
        }

        if (q - p > 0 && !zcnt)
            res = min(res, { q - p, p });
        p++;

        while (p != l) {
            bool is_ok = true;
            for (int i = 0; i < n - 1; i++) {
                if (C[i][p - 1] == 1)
                    if (--Gs[i] == 0) zcnt++;
                if (C[i][p] == 2) is_ok = false;
            }
            if (is_ok) break;
            p++;
        }
    }

    cout << res.second + 1 << ' ' << res.second + res.first;
}