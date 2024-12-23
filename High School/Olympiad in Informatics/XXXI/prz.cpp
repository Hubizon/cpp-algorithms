// Hubert Jastrzębski | XXXI OI I (Przyciski) | 2023-11-03
// https://sio2.mimuw.edu.pl/c/oi31-1/p/prz/

#include <bits/stdc++.h>

using namespace std;

vector<int> isEvenSol(const vector<vector<pair<int, int>>>& G) {
    vector<int> R;
    int n = G.size();
    vector<bool> visited(n);
    function<int(int, int)> cDFS = [&](int u, int p) {
      visited[u] = true;
      for (auto [v, i] : G[u]) {
          if (visited[v] && v != p) {
              R.push_back(i);
              return v;
          }
          if (!visited[v]) {
              int w = cDFS(v, u);
              if (w >= 0) {
                  R.push_back(i);
                  if (u != w)
                      return w;
              }
              if (w != -1)
                  return -2;
          }
      }
      return -1;
    };

    for (int i = 0; i < n; i++)
        if (!visited[i])
            if (cDFS(i, -1) != -1)
                return R;

    return { };
}

vector<int> isOddSol(const vector<vector<pair<int, int>>>& G) {
    vector<int> R;
    int n = G.size();
    vector<bool> visited(n);
    function<bool(int, int)> tDFS = [&](int u, int p) {
      visited[u] = true;
      int cnt = (p != -1);
      for (auto [v, i] : G[u]) {
          if (v != p && tDFS(v, u)) {
              R.push_back(i);
              cnt++;
          }
      }
      if (cnt % 2 == 0)
          return false;
      return true;
    };

    for (int i = 0; i < n; i++)
        if (!visited[i])
            if (!tDFS(i, -1))
                return { };

    return R;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> G(2 * n);
    for (int i = 0; i < m; i++) {
        int r, c;
        cin >> r >> c;
        c += n, --r, --c;
        G[r].push_back({ c, i });
        G[c].push_back({ r, i });
    }

    vector<int> R1 = isEvenSol(G);
    if (R1.empty()) {
        vector<int> R2 = isOddSol(G);
        if (R2.empty())
            cout << "NIE";
        else {
            cout << "TAK\n" << R2.size() << '\n';
            for (auto r : R2)
                cout << r + 1 << ' ';
        }
    }
    else {
        cout << "TAK\n" << R1.size() << '\n';
        for (auto r : R1)
            cout << r + 1 << ' ';
    }
}