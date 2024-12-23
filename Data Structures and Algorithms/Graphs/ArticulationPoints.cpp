// Finding articulation points in a directed graph
// time complexity: O(n) space: O(n)

vector<vector<int>> G(n);

int cnt = 0;
vector<bool> isAP(n);
vector<int> tin(n, -1), low(n);
function<void(int, int)> aDFS = [&](int u, int p = -1) {
	tin[u] = low[u] = cnt++;
	int children = 0;
	for (auto& v : G[u]) {
		if (v == p) continue;
		if (tin[v] == -1)
			aDFS(v, u), children++;
		if (tin[u] > tin[v])
			low[u] = min(low[u], tin[v]);
		else if (tin[u] > low[v])
			low[u] = min(low[u], low[v]);
		else if (p != -1)
			isAP[u] = true;
	}
	if (p == -1 && children > 1)
		isAP[u] = true;
};

for (int u = 0; u < n; u++)
	if (tin[u] == -1)
		aDFS(u);
		