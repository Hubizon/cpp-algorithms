// Hubert Jastrzębski | Krajowe Warsztaty Algorytmiczne PREOI KWA 2022 (Linia Lotnicza) | 2022-02-05
// https://sio2.staszic.waw.pl/c/kwa-2022/p/lot/

#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    if (n == 1) {
        cout << "TAK\n1 1";
        return 0;
    }

    if (n == 4) {
        cout << "TAK\n1 1 3 4 2 3 2 4";
        return 0;
    }

    if (n == 5) {
        cout << "TAK\n1 1 3 4 5 3 2 4 2 5";
        return 0;
    }

    if ((n / 2) % 2) {
        cout << "NIE";
        return 0;
    }

    cout << "TAK\n";
    int k = n / 2;
    for (int i = 2 * k; i >= 2; i -= 2)
        cout << i << ' ';
    cout << 2 * k + ((n % 2) ? 1 : -1) << ' ';
    for (int i = 2; i <= 2 * k; i += 2)
        cout << i << ' ';
    cout << k - 1 << ' ';
    for (int i = 2 * k - 3 + 2 * (n % 2); i >= k + 1; i -= 2)
        cout << i << ' ';
    for (int i = k - 3; i >= 3; i -= 2)
        cout << i << ' ';
    if (n % 2) cout << k - 1 << ' ' << 2 * k + 1 << ' ';
    else cout << 2 * k - 1 << ' ' << k - 1 << ' ';
    for (int i = 3; i <= k - 3; i += 2)
        cout << i << ' ';
    cout << "1 1 ";
    for (int i = k + 1; i <= 2 * k - 3 + 2 * (n % 2); i += 2)
        cout << i << ' ';
}