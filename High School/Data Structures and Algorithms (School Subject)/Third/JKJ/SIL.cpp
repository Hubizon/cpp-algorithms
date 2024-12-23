// Hubert Jastrzębski | Satori SIL (Silos) | 2021-12-23
// https://satori.tcs.uj.edu.pl/contest/1870276/problems/1893563

#include <iostream>
#include <algorithm>
#include <complex>
#include <vector>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, R;
    cin >> n >> R;
    ll s = 0, res = 0;
    vector<pair<double, bool>> V;
    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        auto P = complex<double>(x, y);
        auto A = complex<double>(R * R, -R * sqrt(norm(P) - R * R)) / conj(P);
        auto B = complex<double>(R * R,  R * sqrt(norm(P) - R * R)) / conj(P);
        auto argA = arg(A), argB = arg(B);
        V.push_back({ argA, 1 }), V.push_back({ argB, 0 });
        s += argA > argB;
    }

    sort(V.begin(), V.end());
    for (auto& [k, v] : V) {
        if (v) res += s++;
        else s--;
    }

    cout << res;
}