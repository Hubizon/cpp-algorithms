// BellmanFord (shortest path from source to every other node) - returns true if there is a negative cycle
// time complexity: O(n^3) [O(V * E)], space: O(n)

vector<array<int, 3>> E; // source, dest, weight
vector<int> dist(n, INF);

auto BellmanFord = [&](const int src) {
    dist[src] = 0;
    bool isRelaxed = true;
    for (int i = 0; i < n && isRelaxed; i++) {
        isRelaxed = false;
        for (auto [s, d, w] : E) {
            if (dist[s] != INF && dist[d] > dist[s] + w) {
                dist[d] = dist[s] + w;
                isRelaxed = true;
            }
        }
    }
    return isRelaxed;
};
