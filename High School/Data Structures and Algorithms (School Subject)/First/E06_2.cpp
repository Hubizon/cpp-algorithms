// Hubert Jastrzębski | Satori E06 (placeholder) | 2021-03-22
// https://satori.tcs.uj.edu.pl/contest/6459992/problems/6810014

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio();
    cin.tie(0);

    int z;
    cin >> z;
    while (z--) {
        int n, B;
        cin >> n >> B;

        vector<pair<int, int>> V(n);
        for (auto& [s, v] : V) cin >> s >> v;

        vector<int> K(B + 1);
        for (auto& [its, itv] : V)
            for (int s = B; s >= its; s--)
                K[s] = max(K[s], itv + K[s - its]);

        cout << K[B] << '\n';
    }
}