// Hubert Jastrzębski | PREOI / OWL 2024 (Poczta) | 2024-01-31
// https://sio2.staszic.waw.pl/c/preoi-owl-2024/p/poc/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    ll h;
    cin >> n >> h;

    vector<queue<int>> V(n);
    for (auto& v : V) {
        int k;
        cin >> k;
        for (int i = 0; i < k; i++) {
            int d;
            cin >> d;
            v.push(d);
        }
    }

    priority_queue<array<ll, 3>> Q;
    auto addToQ = [&](int i) {
      ll x = 0, m = 0;
      while (V[i].size() && x <= 0) {
          x += V[i].front();
          m = min(m, x);
          V[i].pop();
      }
      if (x > 0)
          Q.push({ m, x, i });
    };

    for (int i = 0; i < n; i++)
        addToQ(i);

    while (Q.size() && h + Q.top()[0] >= 0) {
        auto [m, x, i] = Q.top();
        Q.pop();
        h += x;
        addToQ(i);
    }

    cout << h;
}