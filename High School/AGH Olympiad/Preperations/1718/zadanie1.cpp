// Hubert Jastrzębski | Diamentowy Indeks AGH 2017/2018 I (Zadanie 1) | 2023-03-04
// https://www.diament.agh.edu.pl/wp-content/uploads/2023/08/matematyka_i_2017_2018.pdf

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;

void solve() {
    ll x;
    cin >> x;
    int n = to_string(x).size();

    vector<ll> pows;
    for (ll i = 0; i <= 9; i++)
        pows.push_back((ll)pow(i, n));

    for (int i = 0; i < n; i++) {
        for (int j = 9; j >= 0; j--) {
            if (x >= pows[j]) {
                cout << j;
                x -= pows[j];
                break;
            }
        }
    }
}

void test() {
    ll x;
    cin >> x;

    ll res = 0;
    string sx = to_string(x);
    int n = sx.size();

    for (auto c : sx) {
        int cx = c - '0';
        res += pow(cx, n);
    }

    cout << res << '\n';
}

int main()
{
    solve();
}
