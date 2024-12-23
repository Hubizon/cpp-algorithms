// Hubert Jastrzębski | Satori F02 (www.sympatia.bt) | 2022-10-06
// https://satori.tcs.uj.edu.pl/contest/7808974/problems/7813436

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Value {
  int d = INT32_MAX, v = INT32_MAX;

  bool operator<(const Value& rhs) const& {
      return d < rhs.d;
  }
};

struct RMQ {
  int n, bs, K;
  vector<Value> M;
  vector<vector<Value>> B;
  vector<int> V;

  RMQ() { };

  RMQ(vector<Value>& m) : M(m), n(m.size()), V(n), bs(__lg(n) + 1), K(__lg((n + bs - 1) / bs) + 1), B(K) {
      B[0] = vector<Value>((n + bs - 1) / bs);
      for (int i = 0, prev = 0, b = 0, r = -1; i < n; i++) {
          if (++r == bs) prev = 0, b++, r = 0;
          B[0][b] = min(B[0][b], M[i]);
          while (prev != 0 && M[i] < M[bs * (b + 1) - __lg(prev ^ (prev - 1)) - 1])
              prev ^= (1 << __lg(prev ^ (prev - 1)));
          prev |= (1 << (bs - r - 1));
          V[i] = prev;
      }

      for (int k = 1; k < K; k++)
          for (int i = 0; i < B[k - 1].size() - (1 << (k - 1)); i++)
              B[k].push_back(min(B[k - 1][i], B[k - 1][i + (1 << (k - 1))]));
  }

  Value query(int p, int q) { // [p, q)
      if (p >= q) return { };

      if (p / bs == (q - 1) / bs)
          return M[bs * (p / bs + 1) - __lg(V[q - 1] & ((1 << (bs - p % bs)) - 1)) - 1];

      Value res;

      int bp = (p + bs - 1) / bs, bq = q / bs;
      if (bp != bq) {
          int k = __lg(bq - bp);
          res = min(B[k][bp], B[k][bq - (1 << k)]);
      }

      if (p % bs != 0)
          res = min(res, M[bs * bp - __lg(V[bs * bp - 1] & ((1 << (bs - p % bs)) - 1)) - 1]);

      if (q % bs != 0)
          res = min(res, M[bs * (bq + 1) - __lg(V[q - 1]) - 1]);

      return res;
  }
};

struct LCA {
  int n;
  vector<vector<int>> G;
  vector<Value> E; // depth, vertex
  vector<int> F;
  RMQ rmq;

  LCA(vector<vector<int>>& G) : n(G.size()), G(G), F(n, -1) {
      DFS(0, 0, 0);
      rmq = RMQ(E);
  }

  void DFS(int u, int p, int d) {
      if (F[u] == -1) F[u] = E.size();
      E.push_back({ d, u });
      for (auto& v : G[u]) {
          if (v == p) continue;
          E.push_back({ d, u });
          DFS(v, u, d + 1);
      }
  }

  int query(int p, int q) {
      auto [fp, fq] = minmax(F[p], F[q]);
      return rmq.query(fp, fq + 1).v;
  }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int z;
    cin >> z;
    while (z--) {
        int n;
        cin >> n;

        vector<vector<int>> G(n);
        for (int i = 1; i < n; i++) {
            int x;
            cin >> x;
            G[x].push_back(i);
        }

        LCA lca(G);

        int m;
        cin >> m;
        while (m--) {
            int a, b;
            cin >> a >> b;
            cout << lca.query(a, b) << '\n';
        }
    }
}