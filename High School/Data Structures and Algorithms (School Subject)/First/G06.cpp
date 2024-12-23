// Hubert Jastrzębski | Satori G06 (Ucieczka) | 2021-04-26
// https://satori.tcs.uj.edu.pl/contest/6459992/problems/6912243

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

void dijkstra(vector<vector<pair<int, int>>>&, vector<int>&);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int z;
    cin >> z;
    while (z--)
    {
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> to_fill;
        vector<vector<pair<int, int>>> G(n, to_fill);
        vector<int> dist(n, INT_MAX);
        for (int i = m; m--;) {
            int a, b, k;
            cin >> a >> b >> k;
            G[a - 1].push_back(make_pair(b - 1, k));
        }

        dijkstra(G, dist);

        if (dist[n - 1] == INT_MAX)
            cout << "BRAK\n";
        else
            cout << dist[n - 1] << '\n';
    }
}

void dijkstra(vector<vector<pair<int, int>>>& G, vector<int>& dist)
{
    dist[0] = 0;
    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    Q.push(make_pair(INT_MAX, 0));

    while (!Q.empty())
    {
        auto [d, u] = Q.top();
        Q.pop();
        if (d != INT_MAX && d != dist[u]) continue;
        for (auto& [a, b] : G[u]) {
            if (dist[a] > dist[u] + b) {
                dist[a] = dist[u] + b;
                Q.push(make_pair(dist[a], a));
            }
        }
    }
}