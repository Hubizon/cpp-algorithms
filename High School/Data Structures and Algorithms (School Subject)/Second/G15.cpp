// Hubert Jastrzębski | Satori G15 (Kamień filozoficzny) | 2022-04-28
// https://satori.tcs.uj.edu.pl/contest/7079339/problems/7576003

#include <iostream>
#include <climits>
#include <string>
#include <vector>
#include <array>
#include <queue>
#include <map>

using namespace std;

typedef long long ll;
typedef array<ll, 3> Node;

struct Distance {
  ll val;

  Distance(ll val = LLONG_MAX) : val(val) { };

  operator ll() {
      return val;
  }

  friend bool operator<(const Distance& lhs, const Distance& rhs)
  {
      return lhs.val < rhs.val;
  }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int z;
    cin >> z;
    while (z--) {
        ll n1, n2, n3, n;
        cin >> n1 >> n2 >> n3 >> n;

        if (n == n1 || n == 0) {
            cout << "0\n";
            continue;
        }

        map<Node, Distance> D;
        priority_queue <pair<Distance, Node>, vector<pair<Distance, Node>>, greater<pair<Distance, Node>>> Q;
        Q.push({ D[{ n1, 0, 0 }] = 0, { n1, 0, 0 } });

        ll res = LLONG_MAX;

        auto addNode = [&](Node v, ll du, ll d) {
          auto& dv = D[v];
          if (dv > du + d)
              Q.push({ dv = du + d, v });
          if (v[0] == n || v[1] == n || v[2] == n)
              res = min(res, (ll)dv);
        };

        while (Q.size()) {
            auto [du, u] = Q.top(); Q.pop();
            auto [a, b, c] = u;
            if (a == n || b == n || c == n) break;
            if (D[u] != du) continue;

            ll d = min(a, n2 - b);
            addNode({ a - d, b + d, c }, du, d);

            d = min(a, n3 - c);
            addNode({ a - d, b, c + d }, du, d);

            d = min(b, n1 - a);
            addNode({ a + d, b - d, c }, du, d);

            d = min(b, n3 - c);
            addNode({ a, b - d, c + d }, du, d);

            d = min(c, n1 - a);
            addNode({ a + d, b, c - d }, du, d);

            d = min(c, n2 - b);
            addNode({ a, b + d, c - d }, du, d);
        }

        cout << (res == LLONG_MAX ? "NIE" : to_string(res)) << '\n';
    }
}