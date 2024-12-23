// Hubert Jastrzębski | XXX OI I (Wyprzedzanie) | 2022-11-11
// https://sio2.mimuw.edu.pl/c/oi30-1/p/wyp/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef unsigned long long ull;

struct Frac {
  ull w, m;

  bool operator<(const Frac& rhs) const { // 2e18 / 1e9 < 2e18 / 1e9
      return (__int128(w) * rhs.m < __int128(rhs.w) * m); // 2e27 < 2e27
  }

  bool operator<=(const Frac& rhs) const { // 1e15 / 1e6 < 2e18 / 1e9
      return (__int128(w) * rhs.m <= __int128(rhs.w) * m); // 1e24 <= 1e24
  }

  Frac operator+(const ull& x) const {
      return { w + x * m, m }; // 2e18 / 1e9
  }

  Frac operator-(const ull& x) const {
      return { w - x * m, m }; // 1e15 / 1e6
  }

  Frac operator*(const Frac& x) const {
      if (w == 0) return { 0, 1 };
      return { w * x.w, m * x.m }; // 1e18 / 1e9
  }
};

struct Vehicle {
  int x, d;
  Frac f;

  pair<Frac, Frac> overtake(const Vehicle& v) const {
      ull X = v.x + d;
      ull M = X * v.f.m, W = f.w * v.f.m - f.m * v.f.w;
      return { { M * f.m, W }, { M * f.w, W } }; // 1e15 / 1e6
  }
};

struct Poly {
  Frac a = { 0, 1 };
  ull b = 1e19;
  Frac operator()(const Frac& x) const {
      return a * x + b; // (1e3 / 1e3) * (1e15 / 1e6) + 1e9
  }
};

// kod częściowo z https://robert1003.github.io/2020/02/06/li-chao-segment-tree.html
template <typename Fun>
struct LiChao {
  int n = 0;
  vector<Frac> V;
  vector<Fun> T;

  LiChao(const vector<Frac>& V) : V(V), n(V.size()), T(4 * n) { }

  void insert(Fun fun) {
      insert(fun, 0, n);
  }

  void insert(Fun fun, int l, int r, int o = 0) {
      if (l + 1 == r) {
          if (fun(V[l]) < T[o](V[l])) T[o] = fun;
          return;
      }

      int mid = (l + r) >> 1, lson = o * 2 + 1, rson = o * 2 + 2;
      bool b1 = fun(V[mid]) < T[o](V[mid]), b2 = fun(V[l]) < T[o](V[l]);
      if (b1) swap(fun, T[o]);
      if (b1 != b2) insert(fun, l, mid, lson);
      else insert(fun, mid, r, rson);
  }

  Frac query(int x) {
      return query(x, 0, n);
  }

  Frac query(int x, int l, int r, int o = 0) {
      if (l + 1 == r) return T[o](V[x]);
      int mid = (l + r) >> 1, lson = o * 2 + 1, rson = o * 2 + 2;
      if (x < mid) return min(T[o](V[x]), query(x, l, mid, lson));
      else return min(T[o](V[x]), query(x, mid, r, rson));
  }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, D, W, M;
    cin >> n >> D >> W >> M;
    Vehicle car = { 0, D, { W, M } };

    vector<Vehicle> V(n);
    for (auto& [x, d, f] : V)
        cin >> x >> d >> f.w >> f.m;

    vector<ull> PS(n + 1);
    for (int i = 0; i < n; i++)
        PS[i + 1] = PS[i] + V[i].d;

    vector<Poly> Funs(n);
    for (int i = 0; i < n; i++)
        Funs[i] = { V[i].f, V[i].x - PS[i + 1] };

    vector<pair<Frac, int>> ToTimes(n);
    vector<Frac> Distances(n);
    for (int i = 0; i < n; i++) {
        auto [t, d] = car.overtake(V[i]);
        ToTimes[i] = { t, i }, Distances[i] = d;
    }

    sort(ToTimes.begin(), ToTimes.end());

    vector<Frac> Times(n);
    vector<int> ITT(n);
    for (int i = 0; i < n; i++) {
        Times[i] = ToTimes[i].first;
        ITT[ToTimes[i].second] = i;
    }

    LiChao<Poly> lc(Times);

    int res = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (Distances[i] - PS[i + 1] <= lc.query(ITT[i]))
            res++;

        lc.insert(Funs[i]);
    }

    cout << res;
}