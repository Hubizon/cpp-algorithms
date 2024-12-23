// Hubert Jastrzębski | Satori P04 (Siła złego) | 2023-02-28
// https://satori.tcs.uj.edu.pl/contest/7808974/problems/8242738

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <array>

using namespace std;

struct Value {
  int v = 0;
};

Value operator+(const Value& lhs, const Value& rhs) {
    return { max(lhs.v, rhs.v) };
};

struct Modifier {
  int m = 0;
};

Modifier operator*(const Modifier& lhs, const Modifier& rhs) {
    return { lhs.m + rhs.m };
}

Value operator*(const Value& val, const Modifier& mod) {
    return { val.v + mod.m };
}

template<typename Value, typename Modifier>
struct Tree {
  struct Node {
    Value value;
    Modifier modifier;
    operator Value() {
        return value * modifier;
    }
  };

  vector<Node> T;
  int L = 1;

  Tree(int n) {
      while (n >= L) L *= 2;
      T = vector<Node>(2 * L);
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

  Value query() {
      return T[1];
  }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int z;
    cin >> z;
    while (z--) {
        int n;
        cin >> n;

        vector<array<int, 4>> E;
        vector<int> PY;
        for (int i = 0; i < n; i++) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            PY.push_back(y1); PY.push_back(y2);
            E.push_back({ x1, -1, y1, y2 });
            E.push_back({ x2, 1, y1, y2 });
        }

        int cnt = 1;
        unordered_map<int, int> M;
        sort(PY.begin(), PY.end());
        for (auto y : PY)
            if (!M.count(y))
                M[y] = cnt++;

        //ale jestem uwu jubert

        int res = 0;
        sort(E.begin(), E.end());
        Tree<Value, Modifier> T(cnt);
        for (auto& [x, t, y1, y2] : E) {
            T.update(M[y1], M[y2] + 1, { -t });
            if (t == -1)
                res = max(res, T.query().v);
        }

        cout << res << '\n';
    }
}