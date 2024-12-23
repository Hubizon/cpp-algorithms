// Hubert Jastrzębski | Krajowe Warsztaty Algorytmiczne PREOI KWA 2022 (Wirus) | 2022-02-09
// https://sio2.staszic.waw.pl/c/kwa-2022/p/wir/

#include <iostream>
#include <functional>
#include <vector>

using namespace std;

typedef int Value;
constexpr Value Default = 1;

struct Tree {
  int L = 1;
  vector<Value> T;

  Tree(const int n) {
      while (L <= n) L *= 2;
      T.resize(2 * L, Default);
      for (int i = L - 1; i > 0; i--)
          T[i] = T[2 * i] +  T[2 * i + 1];
  }

  void update(int x) {
      T[x += L] = 0;
      for (int i = x; i /= 2; T[i] = T[2 * i] + T[2 * i + 1]);
  }

  int query(int pos) {
      int x = 1;
      while (x < L) {
          if (pos <= T[2 * x]) x *= 2;
          else {
              pos -= T[2 * x];
              (x *= 2)++;
          }
      }

      update(x -= L);
      return x;
  }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    cin >> n >> x; --x;
    vector<int> V(n - 2);
    for (auto& v : V) cin >> v;

    vector<vector<int>> G(n);
    int ccnt = 1;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        G[--a].push_back(--b);
        G[b].push_back(a);
    }

    vector<int> P(n); // parents
    function<void(int, int)> pDFS = [&](int u, int p) {
      P[u] = p;
      for (auto v : G[u])
          if (v != p)
              pDFS(v, u);
    };
    pDFS(0, 0);

    vector<int> C(n); // components
    vector<int> S = { n }; // sizes
    function<bool(int, int, int)> sDFS = [&](int u, int p, int steps) {
      if (steps <= 0) return true;
      for (auto& v : G[u])
          if (v != p && C[u] == C[v])
              if (sDFS(v, u, steps - 1))
                  return true;
      return false;
    };

    auto isSmaller = [&](int u, int v) -> bool {
      for (int i = 1; true; i *= 2) {
          auto a = sDFS(u, v, i), b = sDFS(v, u, i);
          if (!a) return true;
          if (!b) return false;
      }
    };

    function<int(int, int)> DFS = [&](int u, int p) {
      int res = 1;
      for (auto& v : G[u])
          if (v != p && C[u] == C[v])
              res += DFS(v, u);
      C[u] = ccnt;
      return res;
    };

    Tree tree(n);
    tree.update(0), tree.update(x);
    for (int i = 0; i < n - 1; i++) {
        int p = P[x];
        if (isSmaller(x, p)) {
            S.push_back(DFS(x, p));
            S[C[p]] -= S.back();
        }
        else {
            S.push_back(DFS(p, x));
            S[C[x]] -= S.back();
        }
        ccnt++;

        int res = S[C[x]];
        cout << res << '\n';
        if (n - i - 2 == 0) break;
        int l = (res + V[i]) % (n - i - 2) + 1;
        x = tree.query(l);
    }
}