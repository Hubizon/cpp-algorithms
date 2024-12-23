// Hubert Jastrzębski | PREOI / OWL 2023 (Zawody drużynowe) | 2023-02-01
// https://sio2.staszic.waw.pl/c/preoi-2023/p/zaw/

#include <iostream>
#include <algorithm>
#include <vector>
#include <array>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<array<int, 3>> X(n), Y(n), Z(n);
    for (int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        X[i] = { x, y, z };
        Y[i] = { y, x, z };
        Z[i] = { z, x, y };
    }

    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    sort(Z.begin(), Z.end());

    while (X.size() && Y.size() && Z.size()) {
        auto [ax, ay, az] = X.back();
        auto [by, bx, bz] = Y.back();
        auto [cz, cx, cy] = Z.back();
        if (ax > bx && ax > cx && by > ay && by > cy && cz > az && cz > bz) {
            cout << ax + by + cz;
            exit(0);
        }
        if (ay >= by || az >= cz)
            X.pop_back();
        else if (bx >= ax || bz >= cz)
            Y.pop_back();
        else
            Z.pop_back();
    }
    cout << -1;
}