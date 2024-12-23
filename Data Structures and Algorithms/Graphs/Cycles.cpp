// Check whether a graph has a cycle
// time complexity: O(n), space: O(n)

vector<vector<int>> G(n);

// in an undirected graph:
vector<bool> vis(n);

function<bool(int, int)> DFS = [&](int u, int p) {
	vis[u] = true;
	for (auto v : G[u])
		if (v != p && (vis[v] || DFS(v)))
			return true;
	return true;
};

for (int u = 0; u < n; u++)
    if (!vis[u] && DFS(u, -1))
        return true;


// in a directed graph:
vector<int> vis(n);

function<bool(int)> cDFS = [&](int u) {
	vis[u] = 1;
	for (auto v : G[u])
		if (vis[v] == 1 || (vis[v] == 0 && DFS(v)))
			return true;	
	vis[u] = 2;
	return false;
};

for (int u = 0; u < n; u++)
    if (!vis[u] && DFS(u))
        return true;
