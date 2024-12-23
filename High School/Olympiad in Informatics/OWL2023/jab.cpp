// Hubert Jastrzębski | PREOI / OWL 2023 (Jabłonie) | 2023-01-31
// https://sio2.staszic.waw.pl/c/preoi-2023/p/jab/

#include <bits/stdc++.h>

using namespace std;

struct Value {
  int v = 0;
};

struct Modifier {
  int m = 0;
};

Modifier operator*(const Modifier& lhs, const Modifier& rhs) {
    return { lhs.m + rhs.m };
}

Value operator*(const Value& lhs, const Modifier& rhs) {
    return { lhs.v + rhs.m };
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

  int L = 1;
  vector<Node> T;

  Tree(const vector<int>& V) {
      while (L <= V.size()) L *= 2;
      T = vector<Node>(2 * L);
      for (int i = 0; i < V.size(); i++)
          T[i + L].value.v = V[i];
  }

  void update(int p, int q, const Modifier& modifier = { 1 }) { // [p, q)
      p += L, q += L;
      if (p >= q) return;
      T[p].modifier = T[p].modifier * modifier;
      while (p / 2 != q / 2) {
          if (p % 2 == 0) T[p + 1].modifier = T[p + 1].modifier * modifier;
          if (q % 2 == 1) T[q - 1].modifier = T[q - 1].modifier * modifier;
          p /= 2, q /= 2;
      }
  }

  Value query(int i) {
      i += L;
      Value res = T[i];
      while (i /= 2)
          res = res * T[i].modifier;
      return res;
  }
};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> V(n);
    for (auto& v : V)
        cin >> v;

    sort(V.begin(), V.end());
    int r = lower_bound(V.begin(), V.end(), V.front()) - V.begin();

    Tree<Value, Modifier> T(V);
    auto binSearch = [&](int x) {
      int a = 0, b = n;
      while (a < b) {
          int mid = (a + b) / 2;
          int q = T.query(mid).v;
          if (q < x)
              a = mid + 1;
          else
              b = mid;
      }
      return a;
    };

    while (m--) {
        string s;
        cin >> s;

        if (s == "zbieraj") {
            int a, b;
            cin >> a >> b;

            auto posa = binSearch(a);
            auto posb = binSearch(b + 1);

            cout << posb - posa << '\n';
        }
        else {
            int x;
            cin >> x;

            if (x == 0) continue;

            if (x + 1 < r) {
                T.update(r - x, r);
                r -= x;
            }
            else {
                int val = T.query(x - 1).v;

                int posa = binSearch(val);
                int posb = binSearch(val + 1);

                T.update(0, posa);
                x -= posa;
                T.update(posb - x, posb);

                r = binSearch(T.query(0).v + 1);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}