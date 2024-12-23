// Finding bridges in an undirected graph (additional steps must be taken if this is a multigraph)
// time complexity: O(n) space: O(n)

vector<vector<int>> G(n);

int cnt = 0;
vector<pair<int, int>> Bridges;
vector<int> tin(n, -1), low(n);
function<void(int, int)> bDFS = [&](int u, int p = -1) {
	tin[u] = low[u] = cnt++;
	for (auto v : G[u]) {
		if (v == p) continue;
		if (tin[v] == -1)
			bDFS(v, u);
		if (tin[u] > tin[v])
			low[u] = min(low[u], tin[v]);
		else if (tin[u] >= low[v])
			low[u] = min(low[u], low[v]);
		else
			Bridges.push_back({ u, v });
	}
};

for (int u = 0; u < n; u++)
	if (tin[u] == -1)
		bDFS(u);
		