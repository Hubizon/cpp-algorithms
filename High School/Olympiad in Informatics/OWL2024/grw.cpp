// Hubert Jastrzębski | PREOI / OWL 2024 (BajtPoints) | 2024-01-29
// https://sio2.staszic.waw.pl/c/preoi-owl-2024/p/grw/

#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
constexpr ll MOD = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, K, J;
    cin >> n >> m >> K >> J;

    int sx = 0, sy = 0, SIZE = (n + 2 * m + 10);
    vector<vector<bool>> V(SIZE, vector<bool>(SIZE));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c;
            cin >> c;
            V[i - j + m][i + j + m] = (c != '#');
            if (c == 'S')
                sx = i - j + m, sy = i + j + m;
        }
    }

    vector<vector<vector<int>>> DP(K + 1, vector<vector<int>>(SIZE, vector<int>(SIZE)));
    DP[0][sx][sy] = 1;

    for (int k = 1; k <= K; k++) {
        vector<vector<int>> PrefSum(SIZE, vector<int>(SIZE));
        for (int x = 1; x < SIZE; x++) {
            for (int y = 1; y < SIZE; y++) {
                PrefSum[x][y] = (1LL * DP[k - 1][x][y] + PrefSum[x - 1][y]
                    + PrefSum[x][y - 1] - PrefSum[x - 1][y - 1] + MOD) % MOD;
            }
        }

        for (int x = 1; x < SIZE; x++) {
            for (int y = 1; y < SIZE; y++) {
                if (V[x][y])
                    DP[k][x][y] = (1LL * PrefSum[min(SIZE - 1, x + J)][min(SIZE - 1, y + J)]
                        - PrefSum[min(SIZE - 1, x + J)][max(0, y - J - 1)]
                        - PrefSum[max(0, x - J - 1)][min(SIZE - 1, y + J)]
                        + PrefSum[max(0, x - J - 1)][max(0, y - J - 1)] + 2 * MOD) % MOD;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            cout << (V[i - j + m][i + j + m] ? DP[K][i - j + m][i + j + m] : -1) << ' ';
        cout << '\n';
    }
}