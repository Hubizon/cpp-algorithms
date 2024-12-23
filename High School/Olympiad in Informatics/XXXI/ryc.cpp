// Hubert Jastrzębski | XXXI OI II (Rycerz) | 2024-02-14
// https://sio2.mimuw.edu.pl/c/oi31-2/p/ryc/

#include <bits/stdc++.h>

using namespace std;

constexpr int INF = 1e9;

struct EdgeBrute {
  int dest = 0;
  vector<int> S;
};

void brute(int n, int m, int d, int k) {
    vector<vector<EdgeBrute>> G(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        vector<int> A(k);
        for (auto& ak : A)
            cin >> ak;
        G[a].push_back({ b, A });
        G[b].push_back({ a, A });
    }

    vector<int> R(k);
    vector<int> TR(k);
    function<void(int, int)> fun = [&](int u, int t) {
      if (t > d)
          return;
      if (u == n - 1) {
          R = max(R, TR);
      }

      for (auto& [dest, A] : G[u]) {
          int pos = -1, prev = -1;
          for (int i = 0; i < k; i++) {
              if (A[i] > TR[i]) {
                  pos = i;
                  prev = TR[i];
                  TR[i] = A[i];
                  break;
              }
          }

          fun(dest, t + 1);

          if (pos != -1)
              TR[pos] = prev;
      }
    };

    fun(0, 0);

    for (auto& r : R)
        cout << r << ' ';
}

struct Edge {
  int a, b;
  int s;
};

void brute2(int n, int m, int d, int k) {
    vector<Edge> E(m);
    vector<vector<int>> G(n);
    for (auto& [a, b, s] : E) {
        cin >> a >> b;
        --a, --b;

        cin >> s;

        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<int> dist1(n, INF), dist2(n, INF);
    auto BFS = [&](int src, vector<int>& dist) {
      queue<int> Q;
      Q.push(src);
      dist[src] = 0;

      while (Q.size()) {
          auto u = Q.front(); Q.pop();
          for (auto& v : G[u]) {
              if (dist[v] == INF) {
                  dist[v] = dist[u] + 1;
                  Q.push(v);
              }
          }
      }
    };

    BFS(0, dist1);
    BFS(n - 1, dist2);

    int r = 0;
    for (auto& [a, b, s] : E) {
        if (s > r && ((dist1[a] + dist2[b] + 1 <= d) || (dist1[b] + dist2[a] + 1 <= d)))
            r = s;
    }

    cout << r;
}

struct EdgeQ {
  vector<int> S;
  int a;
  int t;

  bool operator<(const EdgeQ& rhs) const& {
      if (t > rhs.t)
          return true;
      if (t < rhs.t)
          return false;
      if (S < rhs.S)
          return true;
      if (S > rhs.S)
          return false;
      return (a > rhs.a);
  }
};

void solve(int n, int m, int d, int k) {
    vector<vector<array<int, 3>>> G(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;

        G[a].push_back({ b, -1, 0 });
        G[b].push_back({ a, -1, 0 });
        for (int j = 0; j < k; j++) {
            int ak;
            cin >> ak;
            G[a].push_back({ b, j, ak });
            G[b].push_back({ a, j, ak });
        }
    }

    vector<vector<int>> V(n, vector<int>(k));
    priority_queue<EdgeQ> Q;
    Q.push({ vector<int>(k), 0, 0 });
    while (Q.size()) {
        auto [ur, u, t] = Q.top(); Q.pop();
        if (t > d - 1 || V[u] != ur) continue;
        for (auto& [v, pos, val] : G[u]) {
            if (pos == -1) {
                if (ur > V[v]) {
                    V[v] = ur;
                    Q.push({ ur, v, t + 1 });
                }
            }
            else {
                int prev = ur[pos];
                ur[pos] = val;
                if (ur > V[v]) {
                    V[v] = ur;
                    Q.push({ ur, v, t + 1 });
                }
                ur[pos] = prev;
            }
        }
    }

    for (auto& v : V.back())
        cout << v << ' ';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, d, k;
    cin >> n >> m >> d >> k;

    if (k == 1)
        brute2(n, m, d, k);
    else if (n <= 10 && m <= 10 && d <= 10)
        brute(n, m, d, k);
    else
        solve(n, m, d, k);
}