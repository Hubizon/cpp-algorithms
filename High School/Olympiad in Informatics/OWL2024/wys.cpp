// Hubert Jastrzębski | PREOI / OWL 2024 (Wyspa Sowia) | 2024-02-02
// https://sio2.staszic.waw.pl/c/preoi-owl-2024/p/wys/

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> MValue;

namespace std {
constexpr int P = 1696969;

template<>
struct hash<MValue> {
  size_t operator() (const MValue& x) const& {
      return x.first * P + x.second;
  }
};
}

int main() {
    ios::sync_with_stdio();
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int cnt = 1;
    unordered_map<MValue, int> Mcnt;

    vector<vector<char>> R(n + 2, vector<char>(m + 2));
    vector<vector<bool>> V(n + 2, vector<bool>(m + 2));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c;
            cin >> c;
            R[i][j] = c;
            if (c == 'S') {
                V[i][j] = true;
                Mcnt[{ i, j }] = cnt;
                cnt++;
            }
        }
    }

    vector<vector<vector<pair<int, int>>>> G(n + 2, vector<vector<pair<int, int>>>(m + 2));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!V[i][j]) continue;
            if (V[i - 1][j]) {
                G[i - 1][j].push_back({ i, j });
            }
            if (V[i + 1][j]) {
                G[i + 1][j].push_back({ i, j });
            }
            if (V[i][j - 1]) {
                G[i][j - 1].push_back({ i, j });
            }
            if (V[i][j + 1]) {
                G[i][j + 1].push_back({ i, j });

            }
        }
    }

    //map<array<int, 4>, bool> M; // M[x1][y1][x2][y2] czy sowa z x1, y1 może dojść na pole x2, y2?
    unordered_map<MValue, bitset<1010>> M; // jakie sowy mogą dojść na pozycje względną x1, x2

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!V[i][j]) continue;
            function<void(int, int)> DFS = [&](int x, int y) {
              //M[{ i, j, x, y }] =  true;
              M[{ x - i, y - j }][Mcnt[{ i, j }]] = true;
              for (auto& [vx, vy] : G[x][y]) {
                  if (M[{ vx - i, vy - j }][Mcnt[{ i, j }]] == false)
                      DFS(vx, vy);
              }
            };

            DFS(i, j);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!V[i][j]) continue;
            int mcntij = Mcnt[{ i, j }];
            bitset<1010> BS;
            for (int k = 0; k < 1010; k++)
                BS[k] = true;
            BS[mcntij] = false;
            for (auto [xy, mcnt] : M) {
                auto [x, y] = xy;
                if (M[{ x, y }][mcntij]) {
                    bitset<1010> bs = M[{ x, y }];
                    BS &= bs;
                }
            }
            if (BS != 0) {
                R[i][j] = 'x';
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << R[i][j];
        }
        cout << '\n';
    }
}