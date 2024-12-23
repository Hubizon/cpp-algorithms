// Hubert Jastrzębski | XXXI OI II (Liczniki) | 2024-02-14
// https://sio2.mimuw.edu.pl/c/oi31-2/p/lic/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void brute() {
    int n, m;
    cin >> n >> m;

    vector<int> C(n);
    for (auto& c : C)
        cin >> c;

    vector<int> S(n);
    for (auto& s : S)
        cin >> s;

    vector<vector<int>> V(m, vector<int>(n));
    for (auto& v : V) {
        for (auto& vv : v) {
            cin >> vv;
        }
        sort(v.begin(), v.end());
    }

    vector<int> Ssort = S;
    sort(Ssort.begin(), Ssort.end());
    for (int i = 0; i < n; i++) {
        int prev = Ssort[i];
        for (int j = 0; j < m; j++) {
            if (V[j][i] < prev) {
                cout << "NIE";
                return;
            }
            prev = V[j][i];
        }
    }

    ll res = INT64_MAX;

    function<void(int)> fun = [&](int pos) {
      if (pos == m) {
          for (int i = 0; i < m; i++) {
              for (int j = 0; j < n; j++) {
                  if (i == 0) {
                      if (V[i][j] < S[j])
                          return;
                  }
                  else {
                      if (V[i][j] < V[i - 1][j])
                          return;
                  }
              }
          }

          ll r = 0;
          for (int i = 0; i < n; i++)
              r += (1LL * C[i]) * (V.back()[i] - S[i]);
          res = min(res, r);

          return;
      }
      do {
          fun(pos + 1);
      } while(next_permutation(V[pos].begin(), V[pos].end()));
    };

    fun(0);

    cout << (res == INT64_MAX ? "NIE" : to_string(res));
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> C(n);
    for (auto& c : C)
        cin >> c;

    vector<int> S(n);
    for (auto& s : S)
        cin >> s;

    vector<vector<int>> V(m, vector<int>(n));
    for (auto& v : V) {
        for (auto& vv : v) {
            cin >> vv;
        }
        sort(v.begin(), v.end());
    }

    /*vector<int> Ssort = S;
    sort(Ssort.begin(), Ssort.end());
    for (int i = 0; i < n; i++) {
        int prev = Ssort[i];
        for (int j = 0; j < m; j++) {
            if (V[j][i] < prev) {
                cout << "NIE";
                return;
            }
            prev = V[j][i];
        }
    }*/

    vector<array<ll, 3>> A(n);
    for (int i = 0; i < n; i++)
        A[i] = { C[i], S[i], S[i] };

    sort(A.rbegin(), A.rend());

    for (int i = 0; i < m; i++) {
        multiset<int> VM;
        for (int j = 0; j < n; j++)
            VM.insert(V[i][j]);

        for (auto& [c, s, e] : A) {
            auto it = VM.lower_bound(e);
            if (it == VM.end()) {
                cout << "NIE";
                return;
            }
            e = *it;
            VM.erase(it);
        }
    }

    ll res = 0;
    for (auto& [c, s, e] : A)
        res += (c * (e - s));

    cout << res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}