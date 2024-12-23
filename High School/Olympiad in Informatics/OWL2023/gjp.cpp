// Hubert Jastrzębski | PREOI / OWL 2023 (Gdzie jest pepe?) | 2023-01-30
// https://sio2.staszic.waw.pl/c/preoi-2023/p/gjp/

#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <set>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<array<int, 3>> OX(n), OY(m);
    for (auto& [x1, x2, y] : OX)
        cin >> x1 >> x2 >> y;
    for (auto& [y1, y2, x] : OY)
        cin >> y1 >> y2 >> x;

    sort(OY.begin(), OY.end(), [&](const auto& lhs, const auto& rhs) { return (lhs[2] < rhs[2]); });

    auto check = [&](int d) -> bool {
      vector<array<int, 4>> E;
      for (auto [x1, x2, y] : OX) {
          if (x1 + d > x2 - d) continue;
          E.push_back({ x1 + d, -1, y, y });
          E.push_back({ x2 - d, 1, y, y });
      }
      for (auto& [y1, y2, x] : OY) {
          if (y1 + d > y2 - d) continue;
          E.push_back({ x, 0, y1 + d, y2 - d });
      }
      sort(E.begin(), E.end());

      multiset<int> S;
      for (auto& [x, t, y1, y2] : E) {
          if (t == -1)
              S.insert(y1);
          else if (t == 1)
              S.erase(y1);
          else {
              auto lb = S.lower_bound(y1);
              if (lb != S.end() && *lb <= y2)
                  return true;
          }
      }

      return false;
    };

    int a = 1, b = 1e9 + 10;
    while (a < b) {
        int mid = (a + b) / 2;
        if (check(mid))
            a = mid + 1;
        else
            b = mid;
    }

    cout << a - 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}