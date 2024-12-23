// Hubert Jastrzębski | Satori P02 (Para najbliższych punktów) | 2022-12-21
// https://satori.tcs.uj.edu.pl/contest/7808974/problems/8125513

#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

constexpr ll INF = 1e18;

int main() {
    int z;
    cin >> z;
    while (z--) {
        int n;
        cin >> n;

        vector<pair<int, int>> V(n);
        for (auto& [x, y] : V)
            cin >> x >> y;

        sort(V.begin(), V.end());

        auto dist = [&](int a, int b) {
          ll x = V[b].first - V[a].first;
          ll y = V[b].second - V[a].second;
          return x * x + y * y;
        };

        function<ll(int, int)> fun = [&](int l, int r) -> ll {
          if (r <= l + 1) return INF;

          int mid = (l + r) / 2;
          int x = V[mid].first;
          ll d = min(fun(l, mid), fun(mid, r));

          vector<pair<int, int>> TV(r - l);
          merge(V.begin() + l, V.begin() + mid, V.begin() + mid, V.begin() + r, TV.begin(),
                [&](auto& lhs, auto& rhs) { return lhs.second < rhs.second; });
          copy(TV.begin(), TV.end(), V.begin() + l);

          vector<int> MV;
          for (int i = l; i < r; i++) {
              ll vix = V[i].first - x;
              if (vix * vix <= d)
                  MV.push_back(i);
          }

          ll res = d;
          for (int i = 1; i < MV.size(); i++) {
              int j = i - 1;
              while (j >= 0 && V[MV[i]].second + d >= V[MV[j]].second)
                  res = min(res, dist(MV[i], MV[j])), j--;
          }

          return res;
        };

        cout << fun(0, n) << '\n';
    }
}}