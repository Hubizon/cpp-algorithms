// Hubert Jastrzębski | PREOI / OWL 2024 (Strefy czasowe) | 2024-02-02
// https://sio2.staszic.waw.pl/c/preoi-owl-2024/p/str/

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

struct Value {
  int cnt = 0, ans = 0, pref = 0, suf = 0;
  bool full = false;

  Value() { }

  Value(int cnt) : cnt(cnt) {
      if (cnt != 0)
          ans = pref = suf = full = 1;
  }

  Value(int ans, int pref, int suf, int full) : ans(ans), pref(pref), suf(suf), full(full) { }
};

Value operator+(const Value& lhs, const Value& rhs) {
    int ans = max({ lhs.ans, rhs.ans, lhs.suf + rhs.pref });
    int pref = lhs.pref, suf = rhs.suf;
    if (lhs.full) pref += rhs.pref;
    if (rhs.full) suf += lhs.suf;
    bool full = (lhs.full && rhs.full);
    return { ans, pref, suf, full };
}

Value operator*(const Value& val, const int x) {
    return Value(val.cnt + x);
}

template<typename Value>
struct Tree {
  int L = 1;
  vector<Value> T;

  Tree(const vector<int>& V) {
      while (L <= V.size()) L *= 2;
      T.resize(2 * L);
      for (int i = 0; i < V.size(); i++)
          T[i + L] = Value(V[i]);
      for (int i = L - 1; i > 0; i--)
          T[i] = T[2 * i] + T[2 * i + 1];
  }

  void update(int i, const int x) {
      i += L;
      T[i] = T[i] * x;
      while (i /= 2)
          T[i] = T[2 * i] + T[2 * i + 1];
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
        int n, m;
        cin >> n >> m;

        map<int, int> D;
        map<int, vector<int>> E;
        vector<int> V(n);
        for (auto& v : V) {
            cin >> v;
            D[v / m]++;
            D[v / m + 1];
            D[v / m + 2];
            E[(v / m + 1) * m - v].push_back(v / m);
        }

        unordered_map<int, int> MD;
        vector<int> Days;
        for (auto& [day, cnt] : D) {
            MD[day] = Days.size();
            Days.push_back(cnt);
        }

        int res = 1;
        Tree<Value> T(Days);
        for (auto& [zone, e] : E) {
            for (auto& day : e) {
                T.update(MD[day], -1);
                T.update(MD[day] + 1, 1);
            }

            res = max(res, T.query().ans);
        }

        cout << res << '\n';
    }
}