// Hubert Jastrzębski | Satori D01 (Powrót Naczelnego Statystyka) | 2021-12-20
// https://satori.tcs.uj.edu.pl/contest/7079339/problems/7318317

#include <iostream>
#include <vector>

using namespace std;

typedef int Value;
constexpr Value Default = INT32_MIN;

Value fun(const Value& lhs, const Value& rhs) {
    Value res;
    res = max(lhs, rhs);
    return res;
}

struct Tree {
  int L = 1;
  vector<Value> T;

  Tree(const int n) {
      while (L <= n) L *= 2;
      T.resize(2 * L, Default);
  }

  Tree(const vector<Value> V) {
      while (L <= V.size()) L *= 2;
      T.resize(2 * L, Default);
      copy(V.begin(), V.end(), T.begin() + L);
      for (int i = L - 1; i > 0; i--)
          T[i] = fun(T[2 * i], T[2 * i + 1]);
  }

  void update(int i, const Value x) {
      T[i += L] = x;
      while (i /= 2)
          T[i] = fun(T[2 * i], T[2 * i + 1]);
  }

  int query(int p, int q) { // [p, q)
      if((p += L) >= (q += L)) return 0;
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

        vector<int> V(n);
        for (auto& v : V) cin >> v;
        Tree tree(V);

        while (m--) {
            string s;
            cin >> s;
            if (s == "MAX") {
                int p, q;
                cin >> p >> q;
                cout << tree.query(p - 1, q) << '\n';
            }
            else {
                int k, x;
                cin >> k >> x;
                tree.update(k - 1, x);
            }
        }
    }
}