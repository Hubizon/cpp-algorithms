// Hubert Jastrzębski | Krajowe Warsztaty Algorytmiczne PREOI KWA 2022 (Sumy) | 2022-02-09
// https://sio2.staszic.waw.pl/c/kwa-2022/p/sum/

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> A(n);
    unordered_map<int, int> M;
    for (auto& a : A) {
        cin >> a;
        M[a]++;
    }

    int res = 0;
    sort(A.rbegin(), A.rend());
    for (auto& a : A) {
        if (!M[a]) continue;
        int p = a - 1;
        p |= p >> 1;
        p |= p >> 2;
        p |= p >> 4;
        p |= p >> 8;
        p |= p >> 16;
        if (++p == a) p *= 2;
        if (M[p - a] && (a != p - a || M[a] >= 2)) {
            M[p - a]--, M[a]--, res++;
        }
    }

    cout << res;
}