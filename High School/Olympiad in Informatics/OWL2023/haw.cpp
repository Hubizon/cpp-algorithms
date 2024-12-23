// Hubert Jastrzębski | PREOI / OWL 2023 (Hawajska) | 2023-02-02
// https://sio2.staszic.waw.pl/c/preoi-2023/p/haw/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);


    int z;
    cin >> z;
    while (z--) {
        int a, b, n;
        cin >> a >> b >> n;

        int t = 1e9, d = -1, l = 1e9, r = -1;
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            t = min(t, x);
            d = max(d, x);
            l = min(l, y);
            r = max(r, y);
        }

        --t, --l;
        d = a - d, r = b - r;

        int nimsum = t ^ d ^ l ^ r;
        cout << (nimsum ? "Bajtek\n" : "Bitek\n");
    }
}