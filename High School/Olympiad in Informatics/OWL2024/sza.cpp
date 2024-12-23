// Hubert Jastrzębski | PREOI / OWL 2024 (Szaleństwo Euklidesa) | 2024-02-03
// https://sio2.staszic.waw.pl/c/preoi-owl-2024/p/sza/

#include <iostream>
#include <functional>
#include <vector>

using namespace std;

/*#include <cmath>
#define __gcd gcd
#define __lg log2

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}*/

constexpr int MOD = 1e9 + 7;

struct ValueGCD {
  int v = 1;
};

ValueGCD operator+(const ValueGCD& lhs, ValueGCD& rhs) {
    return { __gcd(lhs.v, rhs.v) };
}

struct ValueMAX {
  int v = INT32_MIN;
  int pos = -1;
};

ValueMAX operator+(const ValueMAX& lhs, ValueMAX& rhs) {
    if (lhs.v > rhs.v)
        return lhs;
    return rhs;
}

template<typename Value>
struct SparseT {
  int K;
  vector<vector<Value>> M;

  SparseT(const vector<Value>& m) : K(__lg(m.size()) + 1), M(K) {
      M[0] = m;

      for (int k = 1; k < K; k++)
          for (int i = 0; i + (1 << (k - 1)) < M[k - 1].size(); i++)
              M[k].push_back(M[k - 1][i] + M[k - 1][i + (1 << (k - 1))]);
  }

  Value query(int p, int q) { // [p, q)
      if (p >= q) return { };
      int k = __lg(q - p);
      return M[k][p] + M[k][q - (1 << k)];
  }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<ValueGCD> Vgcd(n);
    vector<ValueMAX> Vmax(n);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        Vgcd[i] = { a };
        Vmax[i] = { a, i };
    }

    long long res = 0;
    SparseT<ValueGCD> stGCD(Vgcd);
    SparseT<ValueMAX> stMAX(Vmax);
    function<void(int, int)> fun = [&](int l, int r) {
      if (l > r) return;
      if (l == r) {
          res += (1LL * Vgcd[l].v * Vgcd[l].v) % MOD;
          return;
      }

      auto stMAXq = stMAX.query(l, r + 1);
      auto maxVal = stMAXq.v, maxPos = stMAXq.pos;

      auto binSearchL = [&](int start, int end, int x) { // (]
        while (start < end) {
            int middle = start + (end - start + 1) / 2;
            if (stGCD.query(middle, maxPos + 1).v >= x)
                end = middle - 1;
            else
                start = middle;
        }
        return start;
      };

      auto binSearchR = [&](int start, int end, int x) { // [)
        while (start < end) {
            int middle = start + (end - start) / 2;
            if (stGCD.query(maxPos, middle + 1).v >= x)
                start = middle + 1;
            else
                end = middle;
        }
        return start;
      };

      vector<pair<int, int>> L = { { 1, maxVal } }, R = { { 1, maxVal } }; // cnt, gcd

      int posL = maxPos - 1;
      while (posL >= l) {
          auto x = stGCD.query(posL, maxPos + 1).v;
          auto next = binSearchL(l - 1, posL, x);
          L.push_back({ posL - next, x });
          posL = next;
      }

      int posR = maxPos + 1;
      while (posR <= r) {
          auto x = stGCD.query(maxPos, posR + 1).v;
          auto next = binSearchR(posR, r + 1, x);
          R.push_back({ next - posR, x });
          posR = next;
      }

      for (auto [cntL, gcdL] : L)
          for (auto [cntR, gcdR] : R)
              res += (((1LL * cntL * cntR) % MOD) * ((1LL * __gcd(gcdL, gcdR) * maxVal) % MOD)) % MOD;

      fun(l, maxPos - 1);
      fun(maxPos + 1, r);
    };

    fun(0, n - 1);

    cout << res % MOD;
}