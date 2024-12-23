// Hubert Jastrzębski | XXIX OI II (Liczby względnie pierwsze) | 2022-02-16
// https://sio2.mimuw.edu.pl/c/oi29-2/p/lic/

// Hubert Jastrzębski XXIX OI DZIEŃ 1 (LIC)
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, k, c;
    cin >> n >> k >> c;

    for (ll x = 1, cnt = 0, cnt2 = 0; true; x++) {
        if (gcd(n, x) == 1) {
            if (++cnt >= k) {
                if (cnt2++ >= c) return 0;
                cout << x << ' ';
            }
        }
    }
}