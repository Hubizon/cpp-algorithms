// Hubert Jastrzębski | XXXI OI I (Satelity) | 2023-11-11
// https://sio2.mimuw.edu.pl/c/oi31-1/p/sat/

#include <bits/stdc++.h>

using namespace std;

typedef bitset < 1010 > bs;

int clg(int x) {
    int lg = __lg(x);
    return lg + (1 << lg != x);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, p, m;
    cin >> n >> p >> m;

    if (m > n + 2) {
        vector < string > V(2 * n);
        for (int i = 0; i < n; i++) {
            V[i] = string(3 * n, 'A');
            V[i][i] = 'C';
            V[i + n] = string(3 * n, 'B');
        }

        while (p--) {
            int a, b;
            cin >> a >> b;
            --a, --b;
            V[b][a] = 'C';
        }

        int max_index = n;

        function < void(int, int, int) > originate = [ & ](int s, int e, int index) {
          int n = e - s;
          if (n <= 1)
              return;
          max_index = max(max_index, index);
          for (int i = s; i < s + n / 2; i++)
              V[i][index] = 'C';
          originate(s, s + n / 2, index + 1);
          originate(s + n / 2, e, index + 1);
        };

        originate(n, 2 * n, n);

        cout << max_index + 2 << '\n';
        for (auto v: V)
            cout << v.substr(0, max_index + 2) << '\n';
    } else {
        vector < bs > VA(n), VB(n);
        while (p--) {
            int a, b;
            cin >> a >> b;
            --a, --b;
            VA[a][b - n] = true;
            VB[b - n][a] = true;
        }

        unordered_map < bs, vector < int >> MA, MB, M, M2;
        for (int i = 0; i < n; i++)
            MA[VA[i]].push_back(i);

        for (int i = 0; i < n; i++)
            MB[VB[i]].push_back(i + n);

        int resA = 0, resB = 0;
        for (const auto & [k, v]: MA)
            resA = max(resA, (int) v.size());
        for (const auto & [k, v]: MB)
            resB = max(resB, (int) v.size());

        bool isSwapped = (resA > resB);
        bool isSwapped2 = (MA.size() < MB.size());
        if (isSwapped) {
            if (isSwapped == isSwapped2)
                MB.clear();
            else
                M2.swap(MB);
            vector < bs > ().swap(VA);
            vector < bs > ().swap(VB);
            M.swap(MA);
        } else {
            if (isSwapped == isSwapped2)
                MA.clear();
            else
                M2.swap(MA);
            vector < bs > ().swap(VA);
            vector < bs > ().swap(VB);
            M.swap(MB);
        }

        vector < string > R = vector < string > (n, string(n + 1, 'A'));
        vector < string > RB = vector < string > (n, string(n + 1, 'B'));
        R.insert(R.end(), RB.begin(), RB.end());

        function < void(const vector < int > & , int, int, int) > originate = [ & ](const vector < int > & V, int s, int e, int index) {
          int n2 = ceil((e - s) / 2.0);
          if (e - s <= 1 || index >= n + 1)
              return;
          for (int i = s; i < s + n2; i++)
              R[V[i]][index] = 'C';
          originate(V, s, s + n2, index + 1);
          originate(V, s + n2, e, index + 1);
        };

        function < void(const vector < int > & , int, int, int) > revOriginate = [ & ](const vector < int > & V, int s, int e, int index) {
          int n2 = ceil((e - s) / 2.0);
          if (e - s <= 1)
              return;
          if (index >= R[0].size()) {
              for (int i = 0; i < n; i++) {
                  R[i].push_back('A');
                  R[i + n].push_back('B');
              }
          }
          for (int i = s + n2; i < e; i++)
              R[V[i]][index] = 'C';
          revOriginate(V, s, s + n2, index + 1);
          revOriginate(V, s + n2, e, index + 1);
        };

        int index = 0;
        for (const auto & [k, X]: M) {
            vector < int > Y;
            for (int y = 0; y < n; y++)
                if (k[y] == 1)
                    Y.push_back(y + isSwapped * n);

            if (Y.size()) {
                int lg = clg(X.size() + 1);

                for (auto & y: Y)
                    for (int i = index; i < index + lg; i++)
                        R[y][i] = 'C';

                if (1 << __lg(X.size()) == X.size()) {
                    for (auto x: X)
                        R[x][index] = 'C';
                    originate(X, 0, X.size(), index + 1);
                } else {
                    originate(X, 0, X.size(), index);
                    R[X.back()][index + lg - 1] = 'C';
                }
                index += lg;
            }
        }

        int maxsize = 0;
        unordered_map < string, vector < int >> MREPA;
        for (int a = 0; a < n; a++)
            MREPA[R[a]].push_back(a);

        for (const auto & [k, A]: MREPA) {
            if (A.size() > 1) {
                maxsize = max(maxsize, clg(A.size()));
                revOriginate(A, 0, A.size(), index);
            }
        }
        index += maxsize;

        unordered_map < string, vector < int >> MREPB;
        for (int b = n; b < 2 * n; b++)
            MREPB[R[b]].push_back(b);

        for (const auto & [k, B]: MREPB)
            if (B.size() > 1)
                revOriginate(B, 0, B.size(), index);

        bs mask;
        for (int i = R[0].size(); i < mask.size(); i++)
            mask[i] = 1;
        auto check = [ & ](int pos) {
          unordered_set < bs > S;
          for (int i = pos; i < pos + n; i++) {
              bs s;
              for (int j = 0; j < R[0].size(); j++)
                  s[j] = (R[i][j] == 'C');
              if (S.count(~s))
                  return false;
              s |= mask;
              if (S.count(s))
                  return false;
              S.insert(s | mask);
          }
          return true;
        };

        if (!check(0 + n * isSwapped) || R[0].size() > n + 1) {
            if (isSwapped != isSwapped2)
                M.swap(M2);

            R = vector < string > (n, string(n + 1, 'A'));
            RB = vector < string > (n, string(n + 1, 'B'));
            R.insert(R.end(), RB.begin(), RB.end());

            index = 0;
            for (const auto & [k, X]: M) {
                vector < int > Y;
                for (int y = 0; y < n; y++)
                    if (k[y] == 1)
                        Y.push_back(y + isSwapped2 * n);

                if (Y.size()) {
                    for (auto y: Y)
                        R[y][index] = 'C';
                    for (auto x: X)
                        R[x][index] = 'C';

                    index++;
                }
            }

            maxsize = 0;
            MREPA.clear();
            for (int a = 0; a < n; a++)
                MREPA[R[a]].push_back(a);

            for (const auto & [k, A]: MREPA) {
                if (A.size() > 1) {
                    maxsize = max(maxsize, clg(A.size()));
                    revOriginate(A, 0, A.size(), index);
                }
            }
            index += maxsize;

            MREPB.clear();
            for (int b = n; b < 2 * n; b++)
                MREPB[R[b]].push_back(b);

            for (const auto & [k, B]: MREPB)
                if (B.size() > 1)
                    revOriginate(B, 0, B.size(), index);
        }

        cout << R[0].size() << '\n';
        for (auto r: R)
            cout << r << '\n';
    }
}