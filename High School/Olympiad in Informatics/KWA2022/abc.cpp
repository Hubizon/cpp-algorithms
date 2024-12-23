// Hubert Jastrzębski | Krajowe Warsztaty Algorytmiczne PREOI KWA 2022 (ABCDCD) | 2022-02-08
// https://sio2.staszic.waw.pl/c/kwa-2022/p/abc/

#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

constexpr ll MOD = 1e9 + 7;
constexpr ll INV2 = (MOD + 1) / 2;
constexpr ll SIG = 'z' - 'a' + 1 + 'Z' - 'A' + 1 + '9' - '0' + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string C;
    cin >> C;
    int n = C.size();
    vector<ll> L(SIG);
    for (auto& c : C) {
        if (islower(c)) c -= 'a';
        else if (isupper(c)) (c -= 'A') += 'z' - 'a' + 1;
        else (c -= '0') += 'z' - 'a' + 1 + 'Z' - 'A' + 1;
        L[c]++;
    }

    ll SUM = 0, res = 0;
    vector<ll> S(SIG);
    vector<vector<vector<ll>>> DP(SIG, vector<vector<ll>>(SIG, vector<ll>(5)));
    for (int i = n - 1; i >= 0; i--) {
        char a = C[i]; L[a]--;
        for (int b = 0; b < SIG; b++) {
            if (b == a) continue;
            ++DP[b][a][1] %= MOD;
            ll x = DP[a][b][3];
            (DP[b][a][3] += DP[b][a][2]) %= MOD;
            (DP[a][b][2] += DP[a][b][1]) %= MOD;
            (DP[a][b][4] += x) %= MOD;
            (S[a] += x) %= MOD, (S[b] += x) %= MOD, (SUM += x) %= MOD;
            ll r1 = L[b] % MOD, r2 = (SUM - S[a] - S[b] + DP[a][b][4] + DP[b][a][4] + 2 * MOD) % MOD;
            (res += (r1 * r2) % MOD) %= MOD;
        }
    }

    cout << res;
}