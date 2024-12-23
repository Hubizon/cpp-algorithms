// Hubert Jastrzębski | Krajowe Warsztaty Algorytmiczne PREOI KWA 2022 (Osiedle) | 2022-02-05
// https://sio2.staszic.waw.pl/c/kwa-2022/p/osi/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct FindUnion {
  int n = 0;
  int componentsNum;
  vector<int> sizes, P;

  FindUnion(int n) {
      this->n = n;
      componentsNum = n;
      sizes.resize(n, 1);
      P.resize(n);
      for (int i = 0; i < n; i++) P[i] = i;
  }

  int find(int v) {
      if (P[v] != v) P[v] = find(P[v]);
      return P[v];
  }

  int find2(int v) {
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

  bool connected(int v, int u) {
      return find(v) == find(u);
  }

  int componentSize(int v) {
      return sizes[find(v)];
  }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    int nm = (n + 1) * (m + 1);

    FindUnion fu(nm);
    for (int i = 0; i < m; i++) fu.unify(i, i + 1); // lewo
    for (int i = n * (m + 1); i < nm - 1; i++) fu.unify(i, i + 1); // prawo
    for (int i = 0; i < n * (m + 1); i += (m + 1)) fu.unify(i, i + (m + 1)); // dół
    for (int i = m; i < nm - 1; i += (m + 1)) fu.unify(i, i + (m + 1)); // góra

    while (k--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int u = (m + 1) * max(--x1, --x2) + max(--y1, --y2);
        int v = u + 1 + (x1 == x2) * m;

        if (fu.find(u) == fu.find(v)) cout << "NIE\n";
        else {
            cout << "TAK\n";
            fu.unify(u, v);
        }
    }
}