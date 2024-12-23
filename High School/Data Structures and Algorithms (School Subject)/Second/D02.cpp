// Hubert Jastrzębski | Satori D02 (Podatki) | 2021-12-20
// https://satori.tcs.uj.edu.pl/contest/7079339/problems/7318289

#include <iostream>
#include <vector>

using namespace std;

typedef long long Value;
constexpr Value Default = 0;

Value fun(const Value& lhs, const Value& rhs) {
    return lhs + rhs;
}

struct Tree {
  int L = 1;
  vector<Value> T;

  Tree(const int n) {
      while (L <= n) L *= 2;
      T.resize(2 * L, Default);
  }

  void update(int p, int q, const Value x) { // [p, q)
      if ((p += L) >= (q += L)) return;
      T[p] += x;
      while (p / 2 != q / 2) {
          if (p % 2 == 0) T[p + 1] = fun(T[p + 1], x);
          if (q % 2 == 1) T[q - 1] = fun(T[q - 1], x);
          p /= 2, q /= 2;
      }
  }

  int query(int i) {
      int res = T[i += L];
      while (i /= 2)
          res = fun(res, T[i]);
      return res;
  }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int z;
    cin >> z;
    while (z--) {
        int n, m;
        cin >> n >> m;
        Tree tree(n);

        while (m--) {
            char c;
            cin >> c;
            if (c == 'P') {
                int a;
                cin >> a;
                cout << tree.query(a - 1) << '\n';
            }
            else {
                int p, q, x;
                cin >> p >> q >> x;
                tree.update(p - 1, q, x);
            }
        }
    }
}