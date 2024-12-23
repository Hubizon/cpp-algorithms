// Hubert Jastrzębski | Satori D05 (Koleje) | 2022-01-10
// https://satori.tcs.uj.edu.pl/contest/7079339/problems/7358632

#include <iostream>
#include <vector>

using namespace std;


struct Value {
  int v = 0;
};

Value operator+ (const Value& lhs, const Value& rhs) {
    return { max(lhs.v, rhs.v) };
}

struct Modifier {
  int m = 0;
};

Modifier operator* (const Modifier& lhs, const Modifier& rhs) {
    return { lhs.m + rhs.m };
}

Value operator* (const Value& lhs, const Modifier& rhs) {
    return { lhs.v + rhs.m };
}

struct Tree {
  struct Node {
    Value value;
    Modifier modifier;
    operator Value() {
        return value * modifier;
    }
  };

  int L = 1;
  vector<Node> T;

  Tree(int n) {
      while (L <= n) L *= 2;
      T.resize(2 * L);
  }

  void update(int p, int q, const Modifier& modifier) {
      p += L, q += L;
      if (p >= q) return;
      T[p].modifier = T[p].modifier * modifier;
      while (p / 2 != q / 2) {
          if (p % 2 == 0) T[p + 1].modifier = T[p + 1].modifier * modifier;
          if (q % 2 == 1) T[q - 1].modifier = T[q - 1].modifier * modifier;
          p /= 2, q /= 2;
          T[p].value = T[2 * p] + T[2 * p + 1];
          T[q].value = T[2 * q] + T[2 * q + 1];
      }
      while (p /= 2)
          T[p].value = T[2 * p] + T[2 * p + 1];
  }

  Value query(int p, int q) {
      p += L, q += L;
      if (p >= q) return Value();
      Value LRes = T[p], RRes;
      while (p / 2 != q / 2) {
          if (p % 2 == 0) LRes = LRes + T[p + 1];
          if (q % 2 == 1) RRes = T[q - 1] + RRes;
          p /= 2, q /= 2;
          LRes = LRes * T[p].modifier;
          RRes = RRes * T[q].modifier;
      }
      LRes = LRes + RRes;
      while (p /= 2)
          LRes = LRes * T[p].modifier;
      return LRes;
  }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int z;
    cin >> z;
    while (z--) {
        int n, m, q;
        cin >> n >> m >> q;
        Tree T(n);
        while (q--) {
            int p, q, l;
            cin >> p >> q >> l;
            --p, --q;
            if (T.query(p, q).v + l <= m) {
                cout << "T\n";
                T.update(p, q, { l });
            }
            else cout << "N\n";
        }
    }
}