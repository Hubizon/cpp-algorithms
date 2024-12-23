// Hubert Jastrzębski | Satori D03 (Powrót Naczelnego Statystyka II) | 2022-01-03
// https://satori.tcs.uj.edu.pl/contest/7079339/problems/7337427

#include <iostream>
#include <algorithm>
#include <vector>
#include <array>

using namespace std;

typedef array<long long, 4> Value;
constexpr Value Default = { 0, 0, 0, 0 };

Value fun(const Value& lhs, const Value& rhs) {
    Value res;
    auto& [sum, pref, suf, inf] = res;
    sum = lhs[0] + rhs[0];
    pref = max({ lhs[1], lhs[0] + rhs[1], 0LL });
    suf = max({ lhs[2] + rhs[0], rhs[2], 0LL });
    inf = max({ lhs[3], rhs[3], lhs[2] + rhs[1], 0LL });
    return res;
}

struct Tree {
  int L = 1;
  vector<Value> T;

  Tree(const vector<Value>& V) {
      while (L <= V.size()) L *= 2;
      T.resize(2 * L, Default);
      copy(V.begin(), V.end(), T.begin() + L);
      for (int i = L - 1; i > 0; i--)
          T[i] = fun(T[2 * i], T[2 * i + 1]);
  }

  void update(int i, const Value& x) {
      T[i += L] = x;
      while (i /= 2)
          T[i] = fun(T[2 * i], T[2 * i + 1]);
  }

  Value query(int p, int q) { // [p, q)
      if ((p += L) >= (q += L)) return Default;
      Value resL = T[p], resR = Default;
      while (p / 2 != q / 2) {
          if (p % 2 == 0) resL = fun(resL, T[p + 1]);
          if (q % 2 == 1) resR = fun(T[q - 1], resR);
          p /= 2, q /= 2;
      }
      return fun(resL, resR);
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

        vector<Value> V(n);
        for (auto& v : V) {
            int x;
            cin >> x;
            v = { x, x, x, x };
        }

        Tree tree(V);

        while (m--) {
            string s;
            cin >> s;
            if (s == "MAX") {
                int p, q;
                cin >> p >> q;
                cout << tree.query(p - 1, q)[3] << '\n';
            }
            else { // UPDATE
                int k, x;
                cin >> k >> x;
                tree.update(k - 1, { x, x, x, x });
            }
        }
    }
}