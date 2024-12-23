// Hubert Jastrzębski | Krajowe Warsztaty Algorytmiczne PREOI KWA 2022 (Odwiedziny Czerwonego Kapturka) | 2022-02-10
// https://sio2.staszic.waw.pl/c/kwa-2022/p/ock/

#include <iostream>
#include <vector>
#include <cmath>
#include <array>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<array<int, 3>> V(n);
    for (auto& [p, k, x] : V) cin >> p >> k >> x;

    auto fun = [&](int mid) {
      long long sum = 0;
      for (auto& [p, k, x] : V)
          if (p <= mid)
              sum += (min(k, mid) - p) / x + 1;
      return sum;
    };

    int a = 0, b = 1e9 + 1;
    while (a + 1 < b) {
        int mid = a + (b - a) / 2;
        if (fun(mid) % 2) b = mid;
        else a = mid;
    }

    int val = fun(a + 1) - fun(a);
    if (val % 2) cout << a + 1 << ' ' << val;
    else cout << "NIE";
}