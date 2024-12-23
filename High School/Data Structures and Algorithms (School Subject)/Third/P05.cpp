// Hubert Jastrzębski | Satori P05 (Suma prostokątów) | 2023-03-07
// https://satori.tcs.uj.edu.pl/contest/7808974/problems/8268216

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <array>

using namespace std;

struct Value {
  int h = 0, r = 0;
};

Value operator+(const Value& lhs, const Value& rhs) {
    return { lhs.h + rhs.h, lhs.r + rhs.r };
}

struct Modifier {
  int m = 0;
};

Modifier operator*(const Modifier& lhs, const Modifier& rhs) {
    return { lhs.m + rhs.m };
}

Value operator*(const Value& val, const Modifier& mod) {
    return { val.h, mod.m ? val.h : val.r };
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

  Tree(const vector<Value>& V) {
      while (L <= V.size()) L *= 2;
      T = vector<Node>(2 * L);
      for (int i = 0; i < V.size(); i++)
          T[i + L].value = V[i];
      for (int i = L - 1; i >= 1; i--)
          T[i].value = T[2 * i] + T[2 * i + 1];
  }

  void update(int p, int q, const Modifier& modifier) {
      if (p >= q) return;
      p += L, q += L;
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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int z;
    cin >> z;

    while (z--) {
        int n;
        cin >> n;

        vector<int> Y;
        vector<array<int, 4>> E;
        for (int i = 0; i < n; i++) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;

            Y.push_back(y1), Y.push_back(y2);
            E.push_back({ x1, 1, y1, y2 });
            E.push_back({ x2, -1, y1, y2 });
        }


        sort(Y.begin(), Y.end());
        auto e = unique(Y.begin(), Y.end());
        Y.resize(e - Y.begin());

        unordered_map<int, int> M;
        for (int i = 0; i < Y.size(); i++)
            M[Y[i]] = i;

        vector<Value> YLen;
        for (int i = 1; i < Y.size(); i++)
            YLen.push_back({ Y[i] - Y[i - 1] });
        Tree<Value, Modifier> T(YLen);

        long long res = 0;
        sort(E.begin(), E.end());
        int prevX = E.front()[0];
        for (auto& [x, t, y1, y2] : E) {
            res += 1LL * (x - prevX) * T.query().r;
            prevX = x;
            T.update(M[y1], M[y2], { t });
        }

        cout << res << '\n';
    }
}