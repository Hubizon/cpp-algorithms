// Hubert Jastrzębski | PREOI / OWL 2023 (Funkcja Bezkwadratowa) | 2023-02-04
// https://sio2.staszic.waw.pl/c/preoi-2023/p/bez/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr int MOD = 1e9 + 7;

void brute1() {
    const int MAXA = 5000;

    int n;
    cin >> n;

    vector<int> V(n);
    for(auto& v : V)
        cin >> v;

    vector<ll> TB(MAXA, 1);
    for (ll x = 2; x * x < MAXA; x++) {
        ll sq = x * x;
        for (int i = sq; i < MAXA; i += sq) {
            TB[i] = max(TB[i], sq);
        }
    }

    vector<ll> B(MAXA);
    for (ll i = 0; i < MAXA; i++)
        B[i] = i / TB[i];

    ll res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            (res += (B[V[i] * V[j]]) % MOD) %= MOD;
        }
    }

    cout << res;
}

void brute2() {
    const int MAXA = 200'200;

    int n;
    cin >> n;

    vector<int> V(n);
    for(auto& v : V)
        cin >> v;

    vector<bool> IP(MAXA, true);
    vector<int> P;
    for (ll i = 2; i < MAXA; i++) {
        if (IP[i]) {
            P.push_back(i);
            for (ll j = i * i; j < MAXA; j += i) {
                IP[j] = false;
            }
        }
    }

    vector<unordered_map<int, int>> M(n);
    for (int i = 0; i < n; i++) {
        auto& v = V[i];
        for (auto& p : P) {
            while (v % p == 0)
                v /= p, M[i][p]++;
            if (v == 1) break;
        }
    }

    ll res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            unordered_map<int, int> F;
            for (auto [p, cnt] : M[i])
                F[p] += cnt;
            for (auto [p, cnt] : M[j])
                F[p] += cnt;
            ll r = 1;
            for (auto [p, cnt] : F)
                if (cnt % 2 == 1)
                    (r *= p) %= MOD;
            (res += r) %= MOD;
        }
    }

    cout << res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    brute2();
}