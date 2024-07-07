// Dijkstra (shortest path from source to every other node, all weights being >=0)
// time complexity: O(n log(n)) [O((V + E) log(V))], space: O(n)

vector<vector<pair<int, int>>> G(n);
vector<int> dist(n, INF);

auto Dijkstra = [&](const int src) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
	Q.push({ dist[src] = 0, src });

	while (Q.size()) {
		auto [d, u] = Q.top(); Q.pop();
		if (d != dist[u]) continue;
		for (auto& [v, w] : G[u])
			if (dist[v] > d + w)
				Q.push({ dist[v] = d + w, v });
	}
};
