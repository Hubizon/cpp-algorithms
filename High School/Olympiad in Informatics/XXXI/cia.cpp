// Hubert Jastrzębski | XXXI OI II (Ciąg binarny) | 2024-02-15
// https://sio2.mimuw.edu.pl/c/oi31-2/p/cia/

#include <bits/stdc++.h>

using namespace std;

void brute() {
    int n, q;
    cin >> n >> q;

    vector<bool> D;
    bool is_one = true;
    for (int i = 0; i < n; i++) {
        int d;
        cin >> d;
        for (int j = 0; j < d; j++)
            D.push_back(is_one);
        is_one ^= 1;
    }

    for (int i = 0; i < q; i++) {
        int l, r, k;
        cin >> l >> r >> k;

        int res = 0;

        vector<bool> SD = vector<bool>(D.begin() + l - 1, D.begin() + r);
        int sds = SD.size();
        for (int bitmask = 0; bitmask < (1 << sds); bitmask++) {
            vector<bool> T(sds);
            int tk = 0, sum = 0;
            for (int i = 0; i < sds; i++) {
                if ((bitmask >> i) & 1) {
                    T[i] = true;
                    sum++;
                    if (T[i] > SD[i]) {
                        tk = INT32_MAX;
                        break;
                    }
                }
            }

            if (tk != INT32_MAX) {
                for (int i = 0; i < sds - 1; i++)
                    if (T[i] != T[i + 1])
                        tk++;
            }

            if (tk <= k)
                res = max(res, sum);
        }

        cout << res << '\n';
    }
}

struct Node {
  int pref, d;
  bool is_one;

  Node() { }
  Node(int pref, int d, bool is_one) : pref(pref), d(d), is_one(is_one) { }

  bool operator<(const Node& rhs) const& {
      if (pref < rhs.pref)
          return true;
      if (pref > rhs.pref)
          return false;
      return d < rhs.d;
  }
};

void solve() {
    int n, q;
    cin >> n >> q;

    vector<Node> D(n);
    bool is_one = true;
    int pref = 0;
    for (auto& d : D) {
        cin >> d.d;
        pref += d.d;
        d.pref = pref;
        d.is_one = is_one;
        is_one ^= 1;
    }

    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;

        auto dl = lower_bound(D.begin(), D.end(), Node(l, -1, false));
        auto dr = lower_bound(D.begin(), D.end(), Node(r, -1, false));

        vector<pair<int, bool>> SD;
        if (dl == dr) {
            if (dl->is_one)
                cout << r - l + 1 << '\n';
            else
                cout << "0\n";
            continue;
        }
        else {
            if (dl->pref - l + 1 > 0)
                SD.push_back({ dl->pref - l + 1, dl->is_one });

            for (auto it = dl + 1; it != D.end() && it != dr; it++)
                SD.push_back({ it->d, it->is_one });

            if (dr != D.end() && dr->d - (dr->pref - r) > 0)
                SD.push_back({ dr->d - (dr->pref - r), dr->is_one });
        }

        int sum = 0;
        for (auto& [d, is_one] : SD)
            sum += d * is_one;

        int tk = SD.size() - 1;
        if (tk <= k) {
            cout << sum << '\n';
            continue;
        }

        sort(SD.begin() + 1, SD.end() - 1);

        auto getRes = [&](int r, int tk) {
          int pos = 1;
          while (tk > k) {
              if (pos == SD.size() - 1)
                  return 0;
              if (SD[pos].second) {
                  tk -= 2;
                  r -= SD[pos].first;
              }
              pos++;
          }
          return r;
        };

        // nie wywalam
        int res = getRes(sum, tk);

        bool is_one_s = SD.begin()->second, is_one_e = (SD.end() - 1)->second;
        int r_s = sum - SD.begin()->first, r_e = sum - (SD.end() - 1)->first;

        // wywalam z lewej
        if (is_one_s && !is_one_e)
            res = max(res, getRes(r_s, tk - 1));

        // wywalam z prawej
        if (is_one_e && !is_one_s)
            res = max(res, getRes(r_e, tk - 1));

        if (is_one_s && is_one_e) {
            // wywalam z mniejszej jednej
            res = max(res, getRes(max(r_s, r_e), tk - 1));

            // wywalam z obydwu
            res = max(res, getRes(r_s + r_e - sum, tk - 2));
        }

        cout << res << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}