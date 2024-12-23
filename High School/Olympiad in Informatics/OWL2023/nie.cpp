// Hubert Jastrzębski | PREOI / OWL 2023 (Nieszablonowy Szablon) | 2023-02-01
// https://sio2.staszic.waw.pl/c/preoi-2023/p/nie/

#include <iostream>
#include <vector>

using namespace std;

constexpr int MOD = 1e9 + 7;

vector<int> getLPS(const string& S) {
    int n = S.size();
    vector<int> lps(n + 1);
    int t = lps[0] = -1;
    for (int i = 1; i <= n; i++) {
        while (t != -1 && S[t] != S[i - 1])
            t = lps[t];
        lps[i] = ++t;
    }
    return lps;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    string S;
    cin >> n >> k >> S;

    vector<int> LPS = getLPS(S);
    vector<int> PS;
    for (int t = LPS[n]; t != -1; t = LPS[t])
        PS.push_back(t);

    vector<int> DP(k + 1); DP[n] = 1;
    for (int i = n; i <= k; i++) {
        for (auto& ps : PS) {
            int j = i + n - ps;
            if (j <= k)
                (DP[j] += DP[i]) %= MOD;
        }
    }

    cout << DP[k];
}