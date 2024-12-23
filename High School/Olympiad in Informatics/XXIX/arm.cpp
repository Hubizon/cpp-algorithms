// Hubert Jastrzębski | XXIX OI II (Armia klonów) | 2022-02-15
// https://sio2.mimuw.edu.pl/c/oi29-2/p/arm/

#include <iostream>
#include <climits>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, a, b;
    cin >> n >> a >> b; ++n;

    if (a == 1 && b == 1) {
        ll res = 0;
        ll army = 1;
        while (army < n) {
            res += 3;
            army *= 3;
        }

        res -= 3, army /= 3;
        ll d = army / 3;
        if (army + d >= n) {
            cout << res + 1;
            return 0;
        }

        res += 2, army *= 2;
        if (army >= n) {
            cout << res;
            return 0;
        }

        cout << res + 1;
        return 0;
    }


    ll res = LLONG_MAX;
    for (int x = 0; x < (1 << 22); x++) {
        ll time = 0, army = 1, data = 0;
        for (int i = 0; i < 22; i++) {
            if ((x >> i) & 1) {
                time += a;
                data = army;
            }
            else {
                time += b;
                army += data;
            }
            if (army >= n) {
                res = min(res, time);
                break;
            }
        }
    }

    cout << res;
}