// Hubert Jastrzębski | PREOI / OWL 2023 (Duża liczba) | 2023-02-04
// https://sio2.staszic.waw.pl/c/preoi-2023/p/duz/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// brute do 10^15
void brute() {
    string S;
    cin >> S;

    ll res = 0;
    for (int i = 0; i < S.size(); i++) {
        res += stoi(S);
        S = S.back() + S;
        S.pop_back();
    }

    cout << res;
}

void solve() {
    string S;
    cin >> S;
    int n = S.size();

    ll sum = 0;
    for (auto c : S)
        sum += c - '0';

    vector<ll> V(n + 1, sum); V[n] = 0;
    for (int i = 0; i < n; i++) {
        V[i + 1] += V[i] / 10;
        V[i] %= 10;
    }

    while (V.back() >= 10) {
        ll x = V.back() / 10;
        V.back() %= 10;
        V.push_back(x);
    }

    if (V.back() == 0) V.pop_back();
    for (int i = V.size() - 1; i >= 0; i--)
        cout << V[i];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}