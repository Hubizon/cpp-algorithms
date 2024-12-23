// Hubert Jastrzębski | PREOI / OWL 2023 (Świece PRIME) | 2023-02-02
// https://sio2.staszic.waw.pl/c/preoi-2023/p/swi/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr ll MAXX = 1e13 + 10;

vector<ll> P, R;

bool isPrime(ll x) {
    if (x <= 1) return false;
    for (auto& p : P) {
        if (p * p > x)
            return true;
        if (x % p == 0)
            return false;
    }
    return true;
}

void genUtil(string x) {
    for (int i = 1; i <= 9; i++) {
        string t = (to_string(i) + x);
        ll tx = stoll(t);
        if (tx <= MAXX && isPrime(tx)) {
            R.push_back(tx);
            genUtil(t);
        }
    }
}

void genPrime() {
    const ll MAXP = 1e7;
    vector<bool> ISP(MAXP, true);
    for (ll i = 2; i < MAXP; i++) {
        if (ISP[i]) {
            P.push_back(i);
            for (ll j = i * i; j < MAXP; j += i) {
                ISP[j] = false;
            }
        }
    }
}

void GENERATE() {
    genPrime();
    genUtil("");
    sort(R.begin(), R.end());
    //for (auto& r : R)
    //    cout << r << ", ";
}

void solve() {
    int n;
    cin >> n;
    while(n--) {
        ll x;
        cin >> x;
        auto ub = upper_bound(R.begin(), R.end(), x);

        cout << *(ub - 1) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    GENERATE();
    solve();
}