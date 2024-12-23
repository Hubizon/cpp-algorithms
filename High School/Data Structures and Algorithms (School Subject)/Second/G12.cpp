// Hubert Jastrzębski | Satori G12 (Jaś pantoflarz) | 2021-12-17
// https://satori.tcs.uj.edu.pl/contest/7079339/problems/7312255

#include <iostream>
#include <vector>
#include <deque>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();

    int z;
    cin >> z;
    while (z--) {
        int n, m;
        cin >> n >> m;
        vector<vector<pair<int, int>>> G(n);
        for (int i = 0; i < m; i++) {
            int a, b, r;
            cin >> a >> b >> r;
            --a, --b;
            G[a].push_back({ b, r });
            G[b].push_back({ a, r });
        }

        vector<ll> inCnt(n), outCnt(n), maxInDist(n), minOutDist(n), maxPrev(n), minPrev(n);
        inCnt[0] = 1, outCnt[n - 1] = 1, minPrev[n - 1] = n;
        for (int i = 1; i < n; i++) {
            pair<ll, ll> maxv = { 0, 0 };
            for (auto& [v, r] : G[i]) {
                if (v < i) {
                    inCnt[i] += inCnt[v];
                    if (maxv.first < maxInDist[v] + r)
                        maxv = { maxInDist[v] + r, v };
                }
                inCnt[i] %= 1000LL;
            }

            maxInDist[i] = maxv.first;
            maxPrev[i] = maxv.second;
        }

        for (int i = n - 2; i >= 0; i--) {
            pair<ll, ll> minv = { INT64_MAX, 0 };
            for (auto& [v, r] : G[i]) {
                if (v > i) {
                    outCnt[i] += outCnt[v];
                    if (minv.first > minOutDist[v] + r)
                        minv = { minOutDist[v] + r, v };
                }
                outCnt[i] %= 1000;
            }

            minOutDist[i] = minv.first;
            minPrev[i] = minv.second;
        }

        int Q;
        cin >> Q;
        while (Q--) {
            int d;
            cin >> d; --d;
            cout << (inCnt[d] * outCnt[d]) % 1000 << '\n';

            deque<int> R;
            int prev = d, next = d;
            while (prev != 0)
                R.push_front(prev = maxPrev[prev]);
            while (next != n) {
                R.push_back(next);
                next = minPrev[next];
            }

            cout << R.size() << ' ';
            for (auto& r : R) cout << r + 1 << ' ';
            cout << '\n';
        }
    }
}