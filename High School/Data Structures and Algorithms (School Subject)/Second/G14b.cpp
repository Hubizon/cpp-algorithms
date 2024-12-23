// Hubert Jastrzębski | Satori G14b (Loch Czarnoksiężnika) | 2022-04-11
// https://satori.tcs.uj.edu.pl/contest/7079339/problems/7575979

#include <iostream>
#include <functional>
#include <vector>
#include <string>
#include <tuple>
#include <queue>
#include <array>

using namespace std;

typedef tuple<int, int, int> NodeId;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int z;
    cin >> z;
    while (z--) {
        int h, w;
        cin >> h >> w;
        vector<string> V(h + 2);
        V.front() = string(w + 2, '#');
        V.back() = string(w + 2, '#');
        for (int i = 1; i <= h; i++) {
            string s;
            cin >> s;
            V[i] = '#' + s + '#';
        }

        vector<vector<array<int, 2>>> D(h + 2, vector<array<int, 2>>(w + 2, { -1, -1 }));
        queue<NodeId> Q;
        pair<int, int> dest;
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                if (V[i][j] == '@') {
                    Q.push({ i, j, 0 });
                    D[i][j][0] = 0;
                }
                if (V[i][j] == '>')
                    dest = { i, j };
            }
        }

        auto step = [&](NodeId xyz, int d) {
          auto [x, y, z] = xyz;
          if (V[x][y] == '#') return;
          if (D[x][y][z] != -1) return;
          if (V[x][y] == '+' && z) return;
          if (V[x][y] == 'o' && !z) return;
          D[x][y][z] = d; Q.push({ x, y, z });
          if (V[x][y] == '%') {
              D[x][y][!z] = d;
              Q.push({ x, y, !z });
          }
        };

        while (!Q.empty()) {
            auto [x, y, z] = Q.front(); Q.pop();
            auto d = D[x][y][z];
            step({ x - 1, y, z }, d + 1);
            step({ x + 1, y, z }, d + 1);
            step({ x, y - 1, z }, d + 1);
            step({ x, y + 1, z }, d + 1);
        }

        int dd = D[dest.first][dest.second][0];
        cout << (dd == -1 ? "NIE" : to_string(dd)) << '\n';
    }
}