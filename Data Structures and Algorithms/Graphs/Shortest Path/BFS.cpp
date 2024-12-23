// BFS (shortest path from source to every other node, all weights being 1)
// time complexity: O(n) [O(V + E)], space: O(n)

vector<vector<int>> G(n);
vector<int> dist(n, INF);

auto BFS = [&](const int src) {
    dist[src] = 0;
    queue<int> Q; Q.push(src);
    while (Q.size()) {
        auto u = Q.front(); Q.pop();
        for (auto& v : G[u]) {
            if (dist[v] == INF) {
                dist[v] = dist[u] + 1;
                Q.push(v);
            }
        }
    }
};
