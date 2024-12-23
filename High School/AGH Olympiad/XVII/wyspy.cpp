// Hubert Jastrzębski | Diamentowy Indeks AGH XVII 1 (Wyspy) | 2023-10-21
// https://www.diament.agh.edu.pl/wp-content/uploads/2024/01/Etap_I_zadania_Informatyka.pdf

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, a, b;
    cin >> n >> a >> b;

    vector<vector<pair<int, int>>> G(3 * n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            if (x == 1) {
                G[i].push_back({ n + j, x });
                G[i].push_back({ 2 * n + j, x });
            }
            if (x == 5) {
                G[n + i].push_back({ j, x });
                G[n + i].push_back({ 2 * n + j, x });
            }
            if (x == 8) {
                G[2 * n + i].push_back({ j, x });
                G[2 * n + i].push_back({ n + j, x });
            }
        }
    }

    vector<int> dist(3 * n, INF);

    auto Dijkstra = [&](const int src) {
        priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
        Q.push({ dist[src] = 0, src });
		Q.push({ dist[src + n] = 0, src + n });
		Q.push({ dist[src + 2 * n] = 0, src + 2 * n});
        while (!Q.empty()) {
            int d = Q.top().first, u = Q.top().second; Q.pop();
            if (d != dist[u]) continue;
            for (auto& g : G[u]) {
                int v = g.first, w = g.second;
                if (dist[v] > d + w)
                    Q.push({ dist[v] = d + w, v });
            }
        }
    };

    Dijkstra(a);
	
	int res = min({ dist[b], dist[n + b], dist[2 * n + b] });
    cout << (res == INF ? -1 : res);
}