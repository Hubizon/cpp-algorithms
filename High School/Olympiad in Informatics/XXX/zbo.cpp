// Hubert Jastrzębski | XXX OI I (Zboże) | 2022-11-06
// https://sio2.mimuw.edu.pl/c/oi30-1/p/zbo/

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> Node;
constexpr int Prr = 1696969;

namespace std {
template<>
struct hash<Node> {
  size_t operator() (const Node& x) const& {
      return (x.first * Prr) + x.second;
  }
};
}

// kod częściowo z https://robert1003.github.io/2020/01/16/centroid-decomposition.html
struct CentroidDecomposition {
  vector<unordered_set<Node>> G;
  vector<unordered_map<int, int>> dist;
  vector<pair<ll, int>> R;
  vector<ll> resp;
  vector<int> P, size;

  CentroidDecomposition(const vector<unordered_set<Node>>& G) : G(G) {
      int n = G.size();
      dist = vector<unordered_map<int, int>>(n);
      R = vector<pair<ll, int>>(n);
      resp = vector<ll>(n);
      P = vector<int>(n);
      size = vector<int>(n);
      build(0, -1);
  }

  int dfs(int u, int p) {
      size[u] = 1;
      for (auto [v, w] : G[u])
          if (v != p)
              size[u] += dfs(v, u);
      return size[u];
  }

  void dfs2(int u, int p, int c, int d) {
      dist[c][u] = d;
      for (auto [v, w] : G[u])
          if (v != p)
              dfs2(v, u, c, d + w);
  }

  int centroid(int u, int p, int n) {
      for (auto [v, w] : G[u])
          if (v != p && size[v] > n / 2)
              return centroid(v, u, n);
      return u;
  }

  void build(int u, int p) {
      int c = centroid(u, p, dfs(u, p));
      P[c] = p;
      dfs2(c, p, c, 0);

      vector<Node> T(G[c].begin(), G[c].end());
      for (auto [v, w] : T) {
          G[c].erase({ v, w }), G[v].erase({ c, w });
          build(v, c);
      }
  }

  void update(int u) {
      R[u].second++;
      for (int v = P[u], prev = u; v != -1; v = P[v]) {
          R[v].first += dist[v][u], R[v].second++;
          resp[prev] += dist[v][u];
          prev = v;
      }
  }

  ll query(int u) {
      ll r = R[u].first;
      for (int v = P[u], prev = u; v != -1; v = P[v]) {
          r += (R[v].first - resp[prev]) + (1LL * R[v].second - R[prev].second) * dist[v][u];
          prev = v;
      }

      return r;
  }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<unordered_set<Node>> G(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c; --a, --b;
        G[a].insert({ b, c });
        G[b].insert({ a, c });
    }

    CentroidDecomposition T(G);
    T.update(0);

    ll res = 0;
    for (int i = 0; i < k; i++) {
        int d;
        cin >> d; --d;
        res += T.query(d) * 2;
        cout << res << '\n';
        T.update(d);
    }
}