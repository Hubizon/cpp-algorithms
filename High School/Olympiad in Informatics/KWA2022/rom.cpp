// Hubert Jastrzębski | Krajowe Warsztaty Algorytmiczne PREOI KWA 2022 (Romb) | 2022-02-09
// https://sio2.staszic.waw.pl/c/kwa-2022/p/rom/

#include <iostream>
#include <functional>
#include <vector>
#include <array>

using namespace std;

typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ull A, B;
    cin >> A >> B;

    unordered_map<ull, array<int, 4>> W;
    for (ull a = 0, ax = 1; ax <= B; ax *= 2, a++) {
        for (ull b = 0, bx = 1; ax * bx <= B; bx *= 3, b++) {
            for (ull c = 0, cx = 1; ax * bx * cx <= B; cx *= 5, c++) {
                for (ull d = 0, dx = 1; ax * bx * cx * dx <= B; dx *= 7, d++) {
                    W[ax * bx * cx * dx] = { (int)a, (int)b, (int)c, (int)d };
                }
            }
        }
    }

    ull DP[20][60][40][30][30];
    for (int k = 0; k < 20; k++)
        for (int a = 0; a < 60; a++)
            for (int b = 0; b < 40; b++)
                for (int c = 0; c < 30; c++)
                    for (int d = 0; d < 30; d++)
                        DP[k][a][b][c][d] = 0;

    DP[1][0][0][0][0] = 1;
    DP[1][1][0][0][0] = 1;
    DP[1][0][1][0][0] = 1;
    DP[1][0][0][1][0] = 1;
    DP[1][0][0][0][1] = 1;
    DP[1][2][0][0][0] = 1;
    DP[1][3][0][0][0] = 1;
    DP[1][1][1][0][0] = 1;
    DP[1][0][2][0][0] = 1;

    for (int k = 2; k <= 18; k++) {
        for (auto& [w, m] : W) {
            auto [a, b, c, d] = m;
            ull sum = DP[k - 1][a][b][c][d];
            for (int i = 1; i <= 9; i++) {
                if (w % i) continue;
                auto [aw, bw, cw, dw] = W[w / i];
                sum += DP[k - 1][aw][bw][cw][dw];
                sum -= DP[k - 2][aw][bw][cw][dw];
            }
            DP[k][a][b][c][d] = sum;
        }
    }

    function<ull(ull, ull, int, int, int, int)> fun = [&](ull C, ull w, int a, int b, int c, int d) -> ull {
      if (C < 10) {
          if (w <= C) return 1;
          else return 0;
      }
      int k = 0, first;
      ull x = C * 10;
      while (x /= 10) {
          first = x % 10;
          k++;
      }
      ull sum = DP[k - 1][a][b][c][d];
      for (int i = 1; i < first; i++) {
          if (w % i != 0) continue;
          auto [aw, bw, cw, dw] = W[w / i];
          sum += DP[k - 1][aw][bw][cw][dw];
          sum -= DP[k - 2][aw][bw][cw][dw];
      }
      ull pow = 1;
      for (int i = 1; i < k; i++) pow *= 10;
      C -= pow * first;
      if (C && pow / 10 <= C && w / first != 0 && w % first == 0) {
          auto [aw, bw, cw, dw] = W[w / first];
          sum += fun(C, w / first, aw, bw, cw, dw);
          sum -= DP[k - 2][aw][bw][cw][dw];
      }
      return sum;
    };

    ull res = 0;
    for (auto& [w, m] : W) {
        auto [a, b, c, d] = m;
        res += fun(B / w, w, a, b, c, d) - fun((A - 1) / w, w, a, b, c, d);
    }
    cout << res;
}