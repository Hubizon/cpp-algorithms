// Hubert Jastrzębski | PREOI / OWL 2023 (iRobot) | 2023-02-06
// https://sio2.staszic.waw.pl/c/preoi-2023/p/rob/

#include <iostream>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> Vec;

constexpr ll MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> q;

    auto cmp = [&](const Vec& u, const Vec& v) {
      if (u.second * v.second < 0)
          return (u.second > v.second);
      ll ccw = u.first * v.second - u.second * v.first;
      if (ccw == 0) {
          if (u.first == v.first)
              return (u.second < v.second);
          return (u.first < v.first);
      }
      if (u.second == 0) {
          if (u.first < 0)
              return true;
          return (v.second < 0);
      }
      if (v.second == 0) {
          if (v.first < 0)
              return false;
          return (u.second > 0);
      }
      return (ccw < 0);
    };

    bool is00 = true;
    ll X = 0, Y = 0;
    multiset<Vec, decltype(cmp)> V(cmp);

    while (q--) {
        char c;
        cin >> c;
        if (c == 'A') {
            ll x, y;
            cin >> x >> y;
            V.insert({ x, y });
            V.insert({ -x, -y });
            (X += abs(x)) %= MOD;
            (Y += abs(y)) %= MOD;
            if (x != 0 && y != 0)
                is00 = false;
        }
        else if (c == 'D') {
            ll x, y;
            cin >> x >> y;
            V.erase(V.find({ x, y }));
            V.erase(V.find({ -x, -y }));
            X = (X - abs(x) + MOD) % MOD;
            Y = (Y - abs(y) + MOD) % MOD;
        }
        else {
            if (is00) {
                cout << (X * Y) % MOD << '\n';
                continue;
            }

            ll res = 0, px = 0, py = 0;
            for (auto [x, y] : V) {
                if (y < 0 || (y == 0 && x > 0)) break;
                ll tx = (px + x + MOD) % MOD, ty = (py + y + MOD) % MOD;
                (res += (((tx * py) % MOD - (px * ty) % MOD + MOD)) % MOD) %= MOD;
                px = tx, py = ty;
            }

            cout << res << '\n';
        }
    }
}