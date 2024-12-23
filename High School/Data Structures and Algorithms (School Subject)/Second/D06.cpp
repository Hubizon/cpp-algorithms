// Hubert Jastrzębski | Satori D06 (Skrętka) | 2022-02-20
// https://satori.tcs.uj.edu.pl/contest/7079339/problems/7358652

#include <iostream>
#include <vector>
#include <array>

using namespace std;

struct Value {
  array<int, 8> A = { 1, 2, 3, 4, 5, 6, 7, 8 };
};

Value operator+(const Value& lhs, const Value& rhs) {
    Value res;
    for (int i = 0; i < 8; i++)
        res.A[i] = lhs.A[rhs.A[i] - 1];
    return res;
}

struct Tree {
  int L = 1;
  vector<Value> T;

  Tree(const vector<Value>& V) {
      while (L <= V.size()) L *= 2;
      T.resize(2 * L);
      copy(V.begin(), V.end(), T.begin() + L);
      for (int i = L - 1; i > 0; i--)
          T[i] = T[2 * i] + T[2 * i + 1];
  }

  void update(int i, const Value& x) {
      T[i += L] = x;
      while (i /= 2)
          T[i] = T[2 * i] + T[2 * i + 1];
  }
};

istream& operator>> (istream& S, Value& value) {
    for (auto& a : value.A) S >> a;
    return S;
}

ostream& operator<< (ostream& S, const Value& value) {
    for (auto& a : value.A) S << a << ' ';
    return S;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<Value> V(n);
    for (auto& v : V) cin >> v;

    Tree T(V);

    int k;
    cin >> k;
    while (k--) {
        int i;
        Value x;
        cin >> i >> x;
        T.update(i - 1, x);
        cout << T.T[1] << '\n';
    }
}