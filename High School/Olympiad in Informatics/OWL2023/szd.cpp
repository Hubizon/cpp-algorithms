// Hubert Jastrzębski | PREOI / OWL 2023 (Spółka zło Dundersztyca) | 2023-01-30
// https://sio2.staszic.waw.pl/c/preoi-2023/p/szd/

#include <iostream>
#include <vector>
#include <array>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int X, Y, Z;
    cin >> X >> Y >> Z;

    vector<vector<vector<bool>>> M(X + 2, vector<vector<bool>>(Y + 2, vector<bool>(Z + 2, false))); // M[x][y][z]
    for (int z = 1; z <= Z; z++) {
        for (int y = Y; y >= 1; y--) {
            for (int x = 1; x <= X; x++) {
                char c;
                cin >> c;
                M[x][y][z] = (c == 'O');
            }
        }
    }

    int m;
    cin >> m;
    vector<vector<array<int, 2>>> W(X + 1, vector<array<int, 2>>(Y + 1, { -1, -1 })); // winda kursuje miedzy W[x][y][0] a W[x][y][1]
    for (int i = 0; i < m; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        W[a][b] = { c, d };
    }

    int x1, y1, z1, x2, y2, z2;
    cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;

    vector<vector<vector<int>>> dist(X + 2, vector<vector<int>>(Y + 2, vector<int>(Z + 2, INT32_MAX)));
    deque<array<int, 3>> Q;
    Q.push_back({ x1, y1, z1 });
    dist[x1][y1][z1] = 0;

    while (Q.size()) {
        auto [ux, uy, uz] = Q.front(); Q.pop_front();
        const auto du = dist[ux][uy][uz];

        auto check = [&](int vx, int vy, int vz) {
          if (!M[vx][vy][vz] || du + 1 >= dist[vx][vy][vz]) return;
          dist[vx][vy][vz] = du + 1;
          Q.push_back({ vx, vy, vz });
        };

        check(ux - 1, uy, uz);
        check(ux + 1, uy, uz);
        check(ux, uy - 1, uz);
        check(ux, uy + 1, uz);

        auto& [c, d] = W[ux][uy];
        if (c <= uz && uz <= d) {
            for (int z = c; z <= d; z++) {
                if (!M[ux][uy][z] || du >= dist[ux][uy][z]) continue;
                dist[ux][uy][z] = du;
                Q.push_front({ ux, uy, z });
            }
            c = d = -1;
        }
    }

    if (dist[x2][y2][z2] == INT32_MAX)
        cout << -1;
    else
        cout << dist[x2][y2][z2];
}