// Hubert Jastrzębski | PREOI / OWL 2024 (Smacznej Kawusi) | 2024-01-30
// https://sio2.staszic.waw.pl/c/preoi-owl-2024/p/kaw/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Value {
  int d = INT32_MAX;
  int v = -1;

  bool operator<(const Value& rhs) const& {
      return d < rhs.d;
  }
};

template<typename Value>
struct RMQ {
  int K;
  vector<vector<Value>> M;

  RMQ() { }

  RMQ(const vector<Value>& m) : K(__lg(m.size()) + 1), M(K) {
      M[0] = m;

      for (int k = 1; k < K; k++)
          for (int i = 0; i + (1 << (k - 1)) < M[k - 1].size(); i++)
              M[k].push_back(min(M[k - 1][i], M[k - 1][i + (1 << (k - 1))]));
  }

  Value query(int p, int q) {
      int k = __lg(q - p);
      return min(M[k][p], M[k][q - (1 << k)]);
  }
};

template<typename Value>
struct LCA {
  const vector<vector<pair<int, int>>> G;
  vector<Value> E;
  vector<int> F;
  RMQ<Value> rmq;

  LCA(const vector<vector<pair<int, int>>>& G, int root = 0) : G(G), F(G.size(), -1) {
      DFS(root);
      rmq = RMQ<Value>(E);
  }

  void DFS (int u, int d = 0) {
      F[u] = E.size();
      E.push_back({ d, u });
      for (auto [v, i] : G[u]) {
          if (F[v] != -1) continue;
          DFS(v, d + 1);
          E.push_back({ d, u });
      }
  }

  int query(int u, int v) {
      auto [fu, fv] = minmax(F[u], F[v]);
      return rmq.query(fu, fv + 1).v;
  }
};

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<array<ll, 3>> R(n - 1); // c, d, cnt
    vector<vector<pair<int, int>>> G(n); // dest, edge index
    for (int i = 0; i < n - 1; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        --a, --b;
        G[a].push_back({ b, i });
        G[b].push_back({ a, i });
        R[i] = { c, d, 0 };
    }

    vector<int> V(n);
    LCA<Value> lca(G);
    for (int i = 0; i < n - 1; i++) {
        int u = i, v = i + 1;
        int uv = lca.query(u, v);
        V[u]++, V[v]++;
        V[uv] -= 2;
    }

    function<int(int, int)> DFS = [&](int u, int p) {
      int sum = V[u];
      for (auto [v, i] : G[u]) {
          if (v == p) continue;
          R[i][2] = DFS(v, u);
          sum += R[i][2];
      }
      return sum;
    };

    DFS(0, -1);

    ll res = 0;
    for (auto [c, d, cnt] : R)
        res += min(cnt * c, d);

    cout << res;
}