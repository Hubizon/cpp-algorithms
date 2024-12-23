// Hubert Jastrzębski | PREOI / OWL 2023 (Podciągi) | 2023-01-31
// https://sio2.staszic.waw.pl/c/preoi-2023/p/pod/

#include <iostream>
#include <vector>

using namespace std;

constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;

    vector<int> C(1e6 + 1, n + 1);
    vector<int> prev(n);
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        prev[i] = C[v];
        C[v] = i;
    }

    vector<int> DP(n + 2); DP[0] = 1;
    for (int i = 1; i <= n; i++)
        DP[i] = (2LL * DP[i - 1] - DP[prev[i - 1]] + MOD) % MOD;

    cout << DP[n] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}