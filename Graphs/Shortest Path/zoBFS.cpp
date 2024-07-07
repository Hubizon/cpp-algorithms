// 0-1 BFS (shortest path from source to every other node, all weights being 0 or 1)
// time complexity: O(n) [O(V + E)], space: O(n)

vector<vector<pair<int, bool>>> G(n);
vector<int> dist(n, INT32_MAX);

auto BFS = [&](const int src) {
    dist[src] = 0;
    deque<int> Q; Q.push_back(src);
    while (Q.size()) {
        auto u = Q.front(); Q.pop_front();
        for (auto& [v, w] : G[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                if (w == 0) Q.push_front(v);
                else Q.push_back(v);
            }
        }
    }
};
