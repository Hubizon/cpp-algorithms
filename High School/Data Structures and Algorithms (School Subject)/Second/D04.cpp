// Hubert Jastrzębski | Satori D04 (Oficerowie) | 2022-01-03
// https://satori.tcs.uj.edu.pl/contest/7079339/problems/7337552

#include <iostream>
#include <algorithm>
#include <vector>
#include <array>

using namespace std;

typedef int Value;
constexpr Value Default = -1;

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

  void update(int i, const Value& x) {
      if (T[i += L] >= x) return;
      T[i] = x;
      while (i /= 2)
          T[i] = fun(T[2 * i], T[2 * i + 1]);
  }

  int query(int p) { // [p, end)
      Value res = T[p += L];
      while (p / 2) {
          if (p % 2 == 0) res = fun(res, T[p + 1]);
          p /= 2;
      }
      return res;
  }
};

int main()
{
    ios_base::sync_with_stdio();
    cin.tie(0);

    int z;
    cin >> z;
    while (z--) {
        int n, M = 0;
        cin >> n;
        vector<array<int, 3>> V(n);
        for (auto& [a, b, c] : V) {
            cin >> a >> b >> c;
            M = max({ M, a, b, c });
        }

        if (V.size() > 1 && equal(V.begin() + 1, V.end(), V.begin())) {
            cout << "0\n";
            continue;
        }

        sort(V.rbegin(), V.rend());
        Tree tree(M);

        int res = 0;
        for (auto& [a, b, c] : V) {
            if (c > tree.query(b)) res++;
            tree.update(b, c);
        }
        cout << res << '\n';
    }
}