// Hubert Jastrzębski | Satori G09 (Tramwaj) | 2021-11-10
// https://satori.tcs.uj.edu.pl/contest/7079339/problems/7237818

#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>
#include <array>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int z;
    cin >> z;
    while (z--) {
        int n, m;
        cin >> n >> m;

        vector<array<int, 3>> V(m);
        for (auto& [w, a, b] : V) {
            cin >> a >> b >> w;
            --a, --b;
        }

        vector<int> sizes(n, 1), id(n);
        iota(id.begin(), id.end(), 0);

        function<int(int)> find = [&](int p) {
          if (id[p] != p) id[p] = find(id[p]);
          return id[p];
        };

        auto unify = [&](int p, int q) {
          int root1 = find(p), root2 = find(q);
          if (root1 == root2) return;
          if (sizes[root1] < sizes[root2]) {
              sizes[root2] += sizes[root1];
              id[root1] = root2;
          }
          else {
              sizes[root1] += sizes[root2];
              id[root2] = root1;
          }
        };

        auto connected = [&](int p, int q) {
          return find(p) == find(q);
        };

        ll res = 0;
        sort(V.begin(), V.end());
        for (auto& [w, a, b] : V) {
            if (!connected(a, b)) {
                unify(a, b);
                res += w;
            }
        }

        cout << res << '\n';
    }
}