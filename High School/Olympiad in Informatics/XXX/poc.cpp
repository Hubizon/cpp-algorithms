// Hubert Jastrzębski | XXX OI I (Pociąg towarowy) | 2022-11-11
// https://sio2.mimuw.edu.pl/c/oi30-1/p/poc/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    k++;

    vector<int> A(n), B(m);
    for (auto& a : A) cin >> a;
    for (auto& b : B) cin >> b;

    // Znajdujemy wystąpienie w pierwszym i ostatnim możliwym ciągu
    vector<pair<int, int>> V(m, { -1, -1 });

    for (int i = 0, pos = 0; i < n && pos < m; i++)
        if (A[i] == B[pos])
            V[pos++].first = i;

    for (int i = n - 1, pos = m - 1; i >= 0 && pos >= 0; i--)
        if (A[i] == B[pos])
            V[pos--].second = i;

    // ustalanie przedziałów, gdzie może być dany kolor, żeby było ok [l, r]
    vector<vector<pair<int, int>>> C(k);
    for (int i = 0; i < m; i++)
        C[B[i]].push_back(V[i]);

    // połączenie tych przedziałów, zeby były tylko rozłączne
    for (auto& c : C) {
        if (c.size() <= 1) continue;
        sort(c.begin(), c.end());
        vector<pair<int, int>> newc = { c[0] };
        for (int i = 1; i < c.size(); i++) {
            if (newc.back().second + 1 >= c[i].first)
                newc.back().second = max(newc.back().second, c[i].second);
            else
                newc.push_back(c[i]);
        }
        c = newc;
    }

    // po kolei patrzenie, czy dany kolor należy do któregoś z przedziałów
    for (int i = 0; i < n; i++) {
        auto c = C[A[i]];
        auto interval = lower_bound(c.begin(), c.end(), i,
                                    [&](pair<int, int>& mid, int val) { return val > mid.second; });
        cout << (interval != c.end() && interval->first <= i) << ' ';
    }
}