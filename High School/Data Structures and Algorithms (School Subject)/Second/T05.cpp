// Hubert Jastrzębski | Satori T05 (Osadnicy) | 2022-03-21
// https://satori.tcs.uj.edu.pl/contest/7079339/problems/7423954

#include <iostream>
#include <unordered_set>
#include <vector>
#include <array>

using namespace std;

typedef array<long long, 2> Value;
constexpr int P = 1696969;

namespace std {
template<>
struct hash<Value> {
  size_t operator() (const Value& x) const& {
      return (x[0] * P) + x[1];
  }
};
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int z;
    cin >> z;
    while (z--) {
        int n;
        cin >> n;
        vector<int> V(n);
        for (auto& v : V) cin >> v;

        const long long PRIME1 = 1696969, PRIME2 = 1717169;
        const long long MOD = 1e9 + 100501;
        vector<long long> P1(n), P2(n);
        for (long long i = 0, x = 1; i < n; i++)
            P1[i] = ((x *= PRIME1) %= MOD);
        for (long long i = 0, x = 1; i < n; i++)
            P2[i] = ((x *= PRIME2) %= MOD);
        vector<long long> HPre1(n + 1), HPre2(n + 1);
        for (long long i = 0; i < n; i++)
            HPre1[i + 1] = ((HPre1[i] * PRIME1) + V[i]) % MOD;
        for (int i = 0; i < n; i++)
            HPre2[i + 1] = ((HPre2[i] * PRIME2) + V[i]) % MOD;

        auto isOk = [&](int k) {
          int cnt = 0;
          unordered_set<Value> DH;
          for (int i = 0; i <= n - k; i++) {
              Value ssHash = { (HPre1[i + k] + (MOD - HPre1[i]) * P1[k - 1]) % MOD,
                               (HPre2[i + k] + (MOD - HPre2[i]) * P2[k - 1]) % MOD };
              DH.insert(ssHash);
          }
          cnt += DH.size();
          return (cnt == n - k + 1);
        };

        int a = 1, b = n + 1;
        while (a < b) {
            int mid = a + (b - a) / 2;
            if (!isOk(mid)) a = mid + 1;
            else b = mid;
        }

        cout << a << '\n';
    }
}