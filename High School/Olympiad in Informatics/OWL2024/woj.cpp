// Hubert Jastrzębski | PREOI / OWL 2024 (Polityka i partie) | 2024-01-29
// https://sio2.staszic.waw.pl/c/preoi-owl-2024/p/woj/

#include <iostream>
#include <vector>

using namespace std;

struct UnionFind {
  vector<int> P, sizes, enemies;

  UnionFind(const int n) : P(n), sizes(n, 1), enemies(n, -1) {
      for (int i = 0; i < n; i++)
          P[i] = i;
  }

  int find(int u) {
      if (P[u] != u) P[u] = find(P[u]);
      return P[u];
  };

  bool unifyFriend(int u, int v) {
      int root1 = find(u), root2 = find(v);
      if (root1 == root2)
          return true;
      if (enemies[root1] == root2)
          return false;
      if (sizes[root1] < sizes[root2])
          swap(root1, root2);
      sizes[root1] += sizes[root2];
      P[root2] = root1;
      if (enemies[root2] != -1) {
          if (enemies[root1] == -1) {
              enemies[root1] = enemies[root2];
              enemies[enemies[root1]] = root1;
          }
          else {
              unifyFriend(enemies[root1], enemies[root2]);
              int enemy = find(enemies[root1]);
              enemies[root1] = enemy;
              enemies[enemy] = root1;
          }
      }
      return true;
  }

  bool unifyEnemy(int u, int v) {
      int root1 = find(u), root2 = find(v);
      if (root1 == root2)
          return false;
      if (enemies[root1] == root2)
          return true;
      if (enemies[root1] == -1 && enemies[root2] == -1) {
          enemies[root1] = root2;
          enemies[root2] = root1;
      }
      if (enemies[root1] != -1)
          unifyFriend(enemies[root1], root2);
      if (enemies[root2] != -1)
          unifyFriend(enemies[root2], root1);

      return true;
  }

  bool areFriends(int u, int v) {
      return find(u) == find(v);
  }

  bool areEnemies(int u, int v) {
      return enemies[find(u)] == find(v);
  }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    UnionFind uf(n);

    while (m--) {
        int c, a, b;
        cin >> c >> a >> b;
        --a, --b;
        if (c == 1) {
            bool res = uf.unifyFriend(a, b);
            if (!res)
                cout << "-1\n";
        }
        else if (c == 2) {
            bool res = uf.unifyEnemy(a, b);
            if (!res)
                cout << "-1\n";
        }
        else if (c == 3) {
            bool res = uf.areFriends(a, b);
            cout << res << '\n';
        }
        else if (c == 4) {
            bool res = uf.areEnemies(a, b);
            cout << res << '\n';
        }
    }
}