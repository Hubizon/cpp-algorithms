// Hubert Jastrzębski | PREOI / OWL 2024 (Indianie) | 2024-01-30
// https://sio2.staszic.waw.pl/c/preoi-owl-2024/p/ind/

#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> V(m);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        V[i] = { x - 1, y - 1 };
    }

    vector<bitset<2024>> S(n);
    for (int i = 0; i < n; i++) {
        S[i] = 0; S[i][i] = true;
        for (int j = m - 1; j >= 0; j--) {
            auto [x, y] = V[j];
            if (S[i][x] && S[i][y]) {
                S[i] = 0;
                break;
            }
            if (S[i][x] && !S[i][y])
                S[i][y] = true;
            else if (!S[i][x] && S[i][y])
                S[i][x] = true;
        }
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        if (S[i] == 0)
            continue;
        for (int j = i + 1; j < n; j++)
            if (S[j] != 0 && (S[i] & S[j]) == 0)
                res++;
    }

    cout << res;
}