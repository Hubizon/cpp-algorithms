// Hubert Jastrzębski | Krajowe Warsztaty Algorytmiczne PREOI KWA 2022 (Kolej wysokich prędkości wiersze) | 2022-02-08
// https://sio2.staszic.waw.pl/c/kwa-2022/p/kol/

#include <functional>
#include <climits>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

typedef long long ll;

int n, s;

struct LCA {
  int n, L;
  vector<vector<pair<int, int>>> G;

  vector<int> depth;
  vector<vector<int>> jumpp;

  LCA() { }
  LCA(int n) : n(n) {
      L = ceil(log2(n));
      G.resize(n), depth.resize(n);
      jumpp.resize(n, vector<int>(L + 1, -1));
  }

  void DFS(int u, int p) {
      jumpp[u][0] = p;
      depth[u] = depth[p] + 1;
      for (int i = 1; i <= L; i++)
          jumpp[u][i] = jumpp[jumpp[u][i - 1]][i - 1];
      for (auto [v, w] : G[u])
          if (v != p)
              DFS(v, u);
  }

  int query(int u, int v) {
      if (u == v) return u;
      if (depth[u] < depth[v]) swap(u, v);
      for (int i = L; i >= 0; --i)
          if (depth[jumpp[u][i]] >= depth[v])
              u = jumpp[u][i];
      if (u == v) return u;
      for (int i = L; i >= 0; --i) {
          if (jumpp[u][i] != jumpp[v][i]) {
              u = jumpp[u][i];
              v = jumpp[v][i];
          }
      }
      return jumpp[u][0];
  }

  // przyłącz drzewo z wierzchołkiem u do tego z p
  void connect(int u, int p, int w) {
      G[u].push_back({ p, w });
      G[p].push_back({ u, w });
      if (jumpp[p].back() == -1)
          fill(jumpp[p].begin(), jumpp[p].end(), p);
      fill(jumpp[u].begin(), jumpp[u].end(), jumpp[p].back());
      DFS(u, p);
  }
};

struct FindUnion {
  int componentsNum;
  vector<int> sizes, P;

  FindUnion() { }
  FindUnion(int noob) {
      componentsNum = n;
      sizes.resize(n, 1);
      P.resize(n);
      for (int i = 0; i < n; i++) P[i] = i;
  }

  int find(int v) {
      int root = v;
      while (root != P[root]) root = P[root];
      while (v != root) {
          int next = P[v];
          P[v] = root;
          v = next;
      }
      return root;
  }

  void unify(int v, int u) {
      int root1 = find(v), root2 = find(u);
      if (root1 == root2) return;
      if (sizes[root1] >= sizes[root2]) {
          sizes[root1] += sizes[root2];
          P[root2] = root1;
      }
      else {
          sizes[root2] += sizes[root1];
          P[root1] = root2;
      }
      componentsNum--;
  }

  int size(int v) {
      return sizes[find(v)];
  }
};

bool is_first2 = true;

FindUnion fu;
LCA lca;

vector<int> dist;
void setDist(int u, int p) {
    for (auto [v, w] : lca.G[u]) {
        if (v != p) {
            dist[v] = dist[u] + w;
            setDist(v, u);
        }
    }
}

void init(int N, int S) {
    n = N;
    s = S;
    dist.resize(n);
    lca = LCA(n);
    fu = FindUnion(n);
}

void build(int x, int y, int m) {
    int s1 = fu.size(--x), s2 = fu.size(--y);
    fu.unify(x, y);
    if (s1 < s2) swap(x, y);
    lca.connect(y, x, m);
    dist[y] = dist[x] + m;
    setDist(y, x);
}

int path(int x, int y) {
    ll s2a = dist[lca.query(--x, --y)];
    return abs(dist[x] - s2a + dist[y] - s2a);
}