// Hubert Jastrzębski | XXX OI II (Gra w kolorowanie) | 2023-02-15
// https://sio2.mimuw.edu.pl/c/oi30-2/p/gra/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Value {
  int v = 0;
};

Value operator+(const Value& lhs, const Value& rhs) {
    return { lhs.v + rhs.v };
}

Value operator*(const Value& lhs, const Value& rhs) {
    return { lhs.v + rhs.v };
}

template<typename Value>
struct Tree {
  int L = 1;
  vector<Value> T;

  Tree (const vector<int>& V) {
      while (V.size() >= L) L *= 2;
      T = vector<Value>(2 * L);
      for (int i = 0; i < V.size(); i++)
          T[i + L].v = V[i];
      for (int i = L - 1; i > 0; i--)
          T[i] = T[2 * i] + T[2 * i + 1];
  }

  void update(int i, const Value& x) {
      i += L;
      T[i] = T[i] * x;
      while (i /= 2)
          T[i] = T[2 * i] + T[2 * i + 1];
  }

  Value query (int p, int q) {
      if (p >= q) return { };
      p += L, q += L;
      Value resL = T[p], resR = { };
      while (p / 2 != q / 2) {
          if (p % 2 == 0) resL = resL * T[p + 1];
          if (q % 2 == 1) resR = T[q - 1] * resR;
          p /= 2, q /= 2;
      }
      return resL + resR;
  }
};

void brute(const int n, const vector<vector<int>>& G, const int sa, const int sb, const int q) {
    vector<int> A(sa), B(sb);
    for (auto& a : A) {
        cin >> a;
        --a;
    }

    for (auto& b : B) {
        cin >> b;
        --b;
    }

    ll res = 0;
    for (auto a : A) {
        vector<int> sizes(n, 1);
        function<void(int, int)> sDFS = [&](int u, int p) {
          for (auto v : G[u]) {
              if (v == p) continue;
              sDFS(v, u);
              sizes[u] += sizes[v];
          }
        };

        vector<bool> doesWin(n);
        function<void(int, int, int, int)> DFS = [&](int u, int p, int d, int dead) {
          if (sizes[u] >= n - sizes[u])
              dead = d;
          if (dead > 0)
              doesWin[u] = true;
          for (auto v : G[u]) {
              if (v == p) continue;
              DFS(v, u, d + 1, dead - 1);
          }
        };

        sDFS(a, -1);
        DFS(a, -1, 0, 0);

        for (auto b : B) {
            if (a != b && !doesWin[b])
                res++;
        }
    }

    cout << res << '\n';

    /*while (q--) {
        char ab, pm;
        int w;
        cin >> ab >> pm >> w;

    }*/
}

void solve(const int n, const vector<vector<int>>& G, const int sa, const int sb, int q) {
    vector<int> A(sa), B(sb);

    for (auto& a : A) {
        cin >> a;
        --a;
    }

    for (auto& b : B) {
        cin >> b;
        --b;
    }

    vector<int> sizes(n, 1), P(n, 1);
    function<void(int, int)> sDFS = [&](int u, int p) {
      P[u] = p;
      for (auto v : G[u]) {
          if (v == p) continue;
          sDFS(v, u);
          sizes[u] += sizes[v];
      }
    };

    sDFS(0, -1);

    int centroid = 0;
    while (true) {
        int maxSize = 0, maxV = centroid;
        for (auto v : G[centroid]) {
            if (v == P[centroid]) continue;
            if (sizes[v] > maxSize) {
                maxSize = sizes[v];
                maxV = v;
            }
        }
        if (2 * maxSize > n)
            centroid = maxV;
        else
            break;
    }

    bool isBFirst = false;
    if (G[centroid].size() <= 2)
        isBFirst = true;

    vector<array<int, 3>> yasia; // depth, AB, vertex
    vector<int> FA(n), FB(n);

    vector<int> D(n);
    function<void(int, int)> dDFS = [&](int u, int p) {
      yasia.push_back({ D[u], 0, u });
      yasia.push_back({ D[u], 1, u });
      for (auto v : G[u]) {
          if (v == p) continue;
          D[v] = D[u] + 1;
          dDFS(v, u);
      }
    };

    dDFS(centroid, -1);

    sort(yasia.begin(), yasia.end());

    int m = yasia.size();
    for (int i = 0; i < m; i++) {
        auto [d, ab, v] = yasia[i];
        if (isBFirst) {
            if (ab == 0)
                FB[v] = i;
            else
                FA[v] = i;
        }
        else {
            if (ab == 0)
                FA[v] = i;
            else
                FB[v] = i;
        }
    }

    ll res = 0;
    for (int i = 0, temp = 0; i < m; i++) {
        if (yasia[i][1] == isBFirst)
            temp++;
        else
            res += temp;
    }
    if (!isBFirst) res -= n;

    vector<int> APos(m), BPos(m);
    for (int i = 0; i < m; i++) {
        if (yasia[i][1] == isBFirst)
            APos[i] = 1;
        else
            BPos[i] = 1;
    }

    Tree<Value> TA(APos), TB(BPos);

    vector<bool> isINA(n, true), isINB(n, true);
    vector<bool> isINA2(n), isINB2(n);

    for (auto a : A)
        isINA2[a] = true;

    for (auto b : B)
        isINB2[b] = true;

    auto delA = [&](int a) {
      isINA[a] = false;
      int u = FA[a];
      res -= TB.query(u, m + 1).v;
      if (!isBFirst) {
          if (isINB[a])
              res++;
      }
      TA.update(u, { -1 });
    };

    auto addA = [&](int a) {
      isINA[a] = true;
      int u = FA[a];
      res += TB.query(u, m + 1).v;
      if (!isBFirst) {
          if (isINB[a])
              res--;
      }
      TA.update(u, { 1 });
    };

    auto delB = [&](int b) {
      isINB[b] = false;
      int u = FB[b];
      res -= TA.query(0, u).v;
      if (!isBFirst) {
          if (isINA[b])
              res++;
      }
      TB.update(u, { -1 });
    };

    auto addB = [&](int b) {
      isINB[b] = true;
      int u = FB[b];
      res += TA.query(0, u).v;
      if (!isBFirst) {
          if (isINA[b])
              res--;
      }
      TB.update(u, { 1 });
    };

    for (int i = 0; i < n; i++) {
        if (!isINA2[i])
            delA(i);
        if (!isINB2[i])
            delB(i);
    }

    if (n <= 2)
        res = 0;

    cout << res << '\n';
    while (q--) {
        char ab, pm;
        int w;
        cin >> ab >> pm >> w;
        --w;
        if (ab == 'A') {
            if (pm == '+')
                addA(w);
            else
                delA(w);
        }
        else {
            if (pm == '+')
                addB(w);
            else
                delB(w);
        }

        if (n <= 2)
            res = 0;

        cout << res << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> G(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    int sa, sb, q;
    cin >> sa >> sb >> q;

    if (n <= 2000 && q == 0) {
        brute(n, G, sa, sb, q);
    }
    else {
        solve(n, G, sa, sb, q);
    }
}