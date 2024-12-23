// Hubert Jastrzębski | PREOI / OWL 2023 (Oscypki) | 2023-02-05
// https://sio2.staszic.waw.pl/c/preoi-2023/p/osc/

#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> V(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> V[i];

    vector<ll> DP(n + 1); DP[1] = V[1];
    if (n >= 2)
        DP[2] = V[2];
    for (int i = 3; i <= n; i++) {
        DP[i] = max(V[i] + DP[i - 2], V[i] + min(V[i - 1], V[i - 2]) + DP[i - 3]);
    }

    ll sum = 0;
    for (auto& v : V)
        sum += v;

    cout << max(DP[n - 1], DP[n]);
}