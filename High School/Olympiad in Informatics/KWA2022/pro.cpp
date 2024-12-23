// Hubert Jastrzębski | Krajowe Warsztaty Algorytmiczne PREOI KWA 2022 (Prostokąty) | 2022-02-05
// https://sio2.staszic.waw.pl/c/kwa-2022/p/pro/

#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<bool>> M(m, vector<bool>(n));
    while (k--) {
        int x, y;
        cin >> x >> y;
        M[y - 1][x - 1] = true;
    }

    vector<vector<int>> ND(m, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = m - 1, prev = m; j >= 0; j--) {
            ND[j][i] = prev;
            if (M[j][i]) prev = j;
        }
    }

    long long res = 0;
    for (int i = 0; i < m; i++) {
        deque<pair<int, int>> K;
        K.push_back({ 0, n });
        vector<int> R(n + 1);
        for (int j = 0; j < n; j++) {
            if (M[i][j]) {
                K.clear();
                K.push_back({ 0, j });
            }
            else {
                int nd = ND[i][j] - i;
                while (!K.empty() && K.back().first >= nd)
                    K.pop_back();
                auto [d, pos] = K.back();
                R[j] = R[pos];
                if (pos == n) pos = -1;
                R[j] += nd * (j - pos);
                K.push_back({ nd, j });
                res += R[j];
            }
        }
    }

    cout << res;
}