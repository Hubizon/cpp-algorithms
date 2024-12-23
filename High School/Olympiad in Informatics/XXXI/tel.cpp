// Hubert Jastrzębski | XXXI OI II (Telefony) | 2024-02-13
// https://sio2.mimuw.edu.pl/c/oi31-2/p/tel/

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> Edge;

namespace std {
constexpr int P = 1696969;
template<>
struct hash<Edge> {
  size_t operator() (const Edge& x) const& {
      return x.first * P + x.second;
  }
};
}

void solve() {
    int n;
    cin >> n;

    // n == 1? -> m = 1
    // wszystkie takie same? -> m = 2

    vector<vector<int>> V(n);
    map<vector<int>, vector<int>> M;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        bool is_pushed = false;
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            --x;
            if (!is_pushed && x > i) {
                is_pushed = true;
                V[i].push_back(i);
            }
            V[i].push_back(x);
        }
        if (!is_pushed)
            V[i].push_back(i);

        M[V[i]].push_back(i);
    }

    int m = M.size();

    if (n == 1) {
        cout << "1\n1";
        exit(0);
    }

    if (m == 1) {
        cout << "2\n1 ";
        for (int i = 1; i < n; i++)
            cout << 2 << ' ';
        cout << "\n1 2";
        exit(0);
    }

    int cnt = 0;
    vector<int> A(n);
    for (auto& [key, val] : M) {
        for (auto& v : val)
            A[v] = cnt;
        cnt++;
    }

    cnt = 0;
    unordered_set<Edge> Edges;
    for (auto& [key, val] : M) {
        for (auto& v : key) {
            if (A[v] != cnt) {
                auto [i1, i2] = minmax(A[v], cnt);
                Edges.insert({ i1, i2 });
            }
        }
        cnt++;
    }

    cout << m << '\n';
    for (auto& a : A)
        cout << a + 1 << ' ';
    cout << '\n';
    for (auto& [a, b] : Edges)
        cout << a + 1 << ' ' << b + 1 << '\n';
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}