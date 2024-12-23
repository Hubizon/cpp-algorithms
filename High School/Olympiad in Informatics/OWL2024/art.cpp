// Hubert Jastrzębski | PREOI / OWL 2024 (Artyleria) | 2024-02-03
// https://sio2.staszic.waw.pl/c/preoi-owl-2024/p/art/

#include <iostream>
#include <functional>
#include <vector>
#include <cmath>
#include <array>

using namespace std;

typedef pair<int, int> Point;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<Point> P(n);
    for (auto& [x, y] : P)
        cin >> x >> y;

    vector<array<int, 4>> R;
    function<bool(const vector<Point>&, int)> fun = [&](const vector<Point>& P, int k) {
      if (P.size() <= k) {
          for (auto p : P)
              R.push_back({ p.first, p.second, -p.first, 1 });
          return true;
      }
      if (k <= 0)
          return false;

      auto areColinear = [&](const Point& A, const Point& B, const Point& C) {
        auto &[ax, ay] = A;
        auto &[bx, by] = B;
        auto &[cx, cy] = C;
        return (1LL * ax * by + 1LL * bx * cy + 1LL * cx * ay == 1LL * ay * bx + 1LL * by * cx + 1LL * cy * ax);
      };

      for (int i = 0; i <= k; i++) {
          for (int j = i + 1; j <= k; j++) {
              vector<Point> newP;
              for (auto p : P)
                  if (!areColinear(P[i], P[j], p))
                      newP.push_back(p);

              if (fun(newP, k - 1)) {
                  R.push_back({ P[i].first, P[i].second, P[j].first, P[j].second });
                  return true;
              }
          }
      }

      return false;
    };

    if (fun(P, k)) {
        cout << "TAK\n";
        for (auto& [px, py, cx, cy] : R)
            cout << px << ' ' << py << ' ' << cx << ' ' << cy << '\n';
        for (int i = 0; i < k - R.size(); i++)
            cout << R[0][0] << ' ' << R[0][1] << ' ' << R[0][2] << ' ' << R[0][3] << '\n';
    }
    else
        cout << "NIE";
}