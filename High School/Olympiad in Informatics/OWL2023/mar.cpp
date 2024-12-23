// Hubert Jastrzębski | PREOI / OWL 2023 (Marudni jurorzy) | 2023-02-04
// https://sio2.staszic.waw.pl/c/preoi-2023/p/mar/

#include <iostream>
#include <algorithm>
#include <vector>
#include <array>

using namespace std;

struct Value {
  int v = 1e9;
};

Value operator+(const Value& lhs, const Value& rhs) {
    return { max(lhs.v, rhs.v) };
}

template<typename Value>
struct Tree {
  int L = 1;
  vector<Value> T;

  Tree(int n) {
      while (n >= L) L *= 2;
      T = vector<Value>(2 * L);
  }

  int query(const int& x) {
      int pos = 1;
      while (pos < L) {
          if (T[pos *= 2].v < x)
              pos++;
      }
      return pos - L;
  }

  void update(int i, const Value& x) {
      T[i += L] = x;
      while (i /= 2)
          T[i] = T[2 * i] + T[2 * i + 1];
  }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> A(n);
    for (auto& a : A) {
        cin >> a;
        a = min(a, n + 1);
    }

    int q;
    cin >> q;
    vector<array<int, 3>> Q(q);
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        Q[i] = { a - 1, b, i };
    }

    sort(Q.begin(), Q.end());
    Tree<Value> T(n);

    vector<int> F(n + 2), R(q);
    for (int i = n - 1; i >= 0; i--) {
        T.update(A[i], { i });
        while (Q.size() && Q.back()[0] == i) {
            auto [a, b, i] = Q.back(); Q.pop_back();
            R[i] = T.query(b);
        }
    }

    for (auto& r : R)
        cout << r << '\n';
}