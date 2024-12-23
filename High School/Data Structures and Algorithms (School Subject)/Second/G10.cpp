// Hubert Jastrzębski | Satori G10 (Mapa galaktyczna) | 2021-12-05
// https://satori.tcs.uj.edu.pl/contest/7079339/problems/7237861

#include <iostream>
#include <unordered_map>
#include <iomanip>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int z;
    cin >> z;
    while (z--)
    {
        int n;
        cin >> n;
        unordered_map<string, int> CTI(n);
        vector<string> ITC(n);
        for (int i = 0; i < n; i++) {
            string city;
            cin >> city;
            CTI[city] = i;
            ITC[i] = city;
        }

        int m;
        cin >> m;
        vector<vector<pair<int, int>>> G(n);
        for (int i = 0; i < m; i++) {
            string a, b;
            int w;
            cin >> a >> b >> w;
            G[CTI[a]].push_back({ CTI[b], w });
        }

        vector<int> dist(n);
        bool isRelaxed = true;
        for (int i = 0; i < n && isRelaxed; i++) {
            isRelaxed = false;
            for (int s = 0; s < n; s++) {
                for (auto [d, w] : G[s]) {
                    if (dist[d] > dist[s] + w) {
                        dist[d] = dist[s] + w;
                        isRelaxed = true;
                    }
                }
            }
        }

        for (int s = 0; s < n; s++)
            for (auto& [d, w] : G[s])
                w += dist[s] - dist[d];

        cout << setw(12) << ' ';
        for (int i = 0; i < n; i++)
            cout << setw(12) << ITC[i];
        cout << '\n';

        for (int s = 0; s < n; s++) {
            vector<int> R(n, INT32_MAX);
            priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
            Q.push({ R[s] = 0, s });
            while (!Q.empty()) {
                auto [d, u] = Q.top(); Q.pop();
                if (d != R[u]) continue;
                for (auto& [v, w] : G[u])
                    if (R[v] > d + w)
                        Q.push({ R[v] = d + w , v });
            }
            for (int i = 0; i < n; i++) R[i] -= dist[s] - dist[i];
            cout << setw(12) << ITC[s];
            for (auto r : R)
                cout << setw(12) << r;
            cout << '\n';
        }
    }
}