// Hubert Jastrzębski | XXXI OI II (Pojemniki) | 2024-02-15
// https://sio2.mimuw.edu.pl/c/oi31-2/p/poj/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// n, k <= 6
void brute() {
    ll n, k;
    cin >> n >> k;

    vector<ll> V(n);
    for (auto& v : V)
        cin >> v;

    bool is_okk = false;
    vector<vector<pair<int, ll>>> R(n);
    function<bool(int)> fun = [&](int p) {
      if (p > n) return false;

      if (p == n) {
          bool is_allz = true;
          for (auto& v : V)
              if (v != 0)
                  is_allz = false;

          if (is_allz) {
              cout << "TAK\n";
              is_okk = true;
              for (auto& r : R) {
                  cout << r.size() << ' ';
                  for (auto& [ra, rb] : r)
                      cout << ra + 1 << ' ' << rb << ' ';
                  cout << '\n';
              }
              return true;
          }

          return false;
      }

      for (int i = 0; i < n; i++) {
          ll vi = V[i];
          if (V[i] == 0) continue;
          for (int j = i; j < n; j++) {
              ll vj = V[j];
              if (V[j] == 0) continue;
              if (vi + vj <= k) {
                  V[i] = V[j] = 0;
                  R[p].push_back({ i, vi });
                  R[p].push_back({ j, vj });
                  if (fun(p + 1))
                      return true;
                  R[p].pop_back();
                  R[p].pop_back();
              }
              else {
                  for (int q = 0; q < min(vi, k); q++) {
                      V[i] = vi - q;
                      V[j] = max(vj - (k - q), 0LL);
                      if (V[i] != vi)
                          R[p].push_back({ i, vi - V[i] });
                      if (V[j] != vj)
                          R[p].push_back({ j, vj - V[j] });
                      if (fun(p + 1))
                          return true;
                      if (V[i] != vi)
                          R[p].pop_back();
                      if (V[j] != vj)
                          R[p].pop_back();
                  }
              }

              V[i] = vi;
              V[j] = vj;
          }
      }

      return false;
    };

    fun(0);

    if (is_okk == false);
    cout << "NIE";
}

// jedno takie ai > k
void brute2() {
    ll n, k;
    cin >> n >> k;

    vector<pair<ll, int>> V(n);
    for (int i = 0; i < n; i++) {
        ll v;
        cin >> v;
        V[i] = { v, i };
    }
    sort(V.rbegin(), V.rend());

    ll r = max(0LL, V.begin()->first - k);
    vector<vector<pair<int, ll>>> R(n);
    R[0] = { { V.begin()->second, min(k, V.begin()->first) } };
    for (int i = 1; i < n; i++) {
        ll vi = V[i].first;
        R[i].push_back({ V[i].second, vi });
        if (r > 0) {
            ll sus = min(r, k - vi);
            if (sus > 0) {
                r -= sus;
                R[i].push_back({ V.begin()->second, sus });
            }
        }
    }

    if (r > 0)
        cout << "NIE";
    else {
        cout << "TAK\n";
        for (auto& r : R) {
            cout << r.size() << ' ';
            for (auto& [ra, rb] : r)
                cout << ra + 1 << ' ' << rb << ' ';
            cout << '\n';
        }
    }
}

void solve() {
    ll n, k;
    cin >> n >> k;

    vector<ll> V(n);
    for (auto& v : V)
        cin >> v;

    vector<vector<pair<int, ll>>> R(n);
    //vector<pair<ll, int>> A; // potrzebne do zapełnienia
    priority_queue<pair<ll, int>> A;
    vector<pair<ll, int>> B; // puste miejsca
    for (int i = 0; i < n; i++) {
        ll vi = V[i];
        if (vi == k)
            R[i].push_back({ i, vi });
        else if (vi > k) {
            R[i].push_back({ i, k });
            A.push({ vi - k, i });
        }
        else if (vi < k) {
            R[i].push_back({ i, vi });
            B.push_back({ k - vi, i });
        }
    }

    sort(B.rbegin(), B.rend());
    for (int i = 0; i < B.size(); i++) {
        if (A.empty()) break;
        auto [av, a] = A.top(); A.pop();
        auto [bv, b] = B[i];
        if (bv >= av) {
            R[b].push_back({ a, av });
        }
        else {
            R[b].push_back({ a, bv });
            A.push({ av - bv, a });
        }
    }

    if (A.size() > 0)
        cout << "NIE";
    else {
        cout << "TAK\n";
        for (auto& r : R) {
            cout << r.size() << ' ';
            for (auto& [ra, rb] : r)
                cout << ra + 1 << ' ' << rb << ' ';
            cout << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ll n, k;
    //cin >> n >> k;

    solve();
}