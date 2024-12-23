// Hubert Jastrzębski | XXXI OI I (Budowa lotniska) | 2023-11-02
// https://sio2.mimuw.edu.pl/c/oi31-1/p/bud/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m; ++n;

    vector<vector<bool>> M(n, vector<bool>(n, true));
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            char c;
            cin >> c;
            M[i][j] = (c != '.');
        }
    }

    vector<array<int, 5>> V; // len, pos, i, j, isVertical
    for (int i = 0; i < n; i++) {
        int pos = -1;
        for (int j = 0; j < n; j++) {
            if (M[i][j] && pos != -1) {
                V.push_back({ j - pos, pos, i, j, 0 });
                pos = -1;
            }
            else if (!M[i][j] && pos == -1)
                pos = j;
        }
    }

    for (int j = 0; j < n; j++) {
        int pos = -1;
        for (int i = 0; i < n; i++) {
            if (M[i][j] && pos != -1) {
                V.push_back({ i - pos, pos, i, j, 1 });
                pos = -1;
            }
            else if (!M[i][j] && pos == -1)
                pos = i;
        }
    }

    sort(V.begin(), V.end());

    auto maxr = [&](array<int, 5> a, array<int, 5> b) -> int { // a - vertical
      auto [lena, posa, ia, ja, iva] = a;
      auto [lenb, posb, ib, jb, ivb] = b;
      if (ja >= jb || ja < posb || ib >= ia || ib < posa)
          return min(lena, lenb);
      return max(min(lena, max(ja - posb, jb - ja - 1)), min(lenb, max(ib - posa, ia - ib - 1)));
    };

    if (V.empty())
        cout << 0;
    else if (m == 1)
        cout << V.back()[0];
    else if (V.size() == 1)
        cout << V.back()[0] / 2;
    else if (V.size() == 2) {
        auto a = V.back(), b = V.front();
        int res = a[0] / 2;
        if (a[4] == b[4])
            res = max(res, b[0]);
        else {
            if (a[4])
                res = max(res, maxr(a, b));
            else
                res = max(res, maxr(b, a));
        }
        cout << res;
    }
    else {
        auto a = *V.rbegin(), b = *(V.rbegin() + 1), c = *(V.rbegin() + 2);
        int res = max(a[0] / 2, c[0]);
        if (a[4] == b[4])
            res = max(res, b[0]);
        else {
            if (a[4])
                res = max(res, maxr(a, b));
            else
                res = max(res, maxr(b, a));
        }
        cout << res;
    }
}