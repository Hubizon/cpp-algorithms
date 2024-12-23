// Hubert Jastrzębski | Satori H05 (Rakieta) | 2022-10-27
// https://satori.tcs.uj.edu.pl/contest/7808974/problems/8008092

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

constexpr int INF = 1e9;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int z;
    cin >> z;
    while (z--) {
        int n;
        cin >> n;

        vector<pair<int, int>> V(n);
        for (auto& [m, w] : V)
            cin >> m >> w;

        sort(V.begin(), V.end(), [&](auto& lhs, auto& rhs)
        { return lhs.first + lhs.second < rhs.first + rhs.second; });

        priority_queue<int> Q;
        long long M = V[0].first;
        Q.push(M);

        for (int i = 1; i < n; i++) {
            if (V[i].second >= M) {
                Q.push(V[i].first);
                M += V[i].first;
            }
            else if (V[i].first < Q.top()) {
                M += V[i].first - Q.top(); Q.pop();
                Q.push(V[i].first);
            }
        }

        cout << Q.size() << '\n';
    }
}