// strongly connected components in a directed graph (Kosaraju's algorithm):
// time complexity: O(n) [O(V + E)], space: O(n)

vector<vector<int>> G(n), RG(n);
vector<bool> vis(n);
stack<int> S;

function<void(int)> TSort = [&](int u) {
	if (vis[u]) return;
	vis[u] = true;
	for (auto v : G[u])
		TSort(v);
	S.push(u);
};

for (int u = 0; u < n; u++)
	TSort(u);

vector<int> SCC(n, -1);
int c = 0;

function<void(int)> rDFS = [&](int u) {
	SCC[u] = c;
	for (auto& v : RG[u])
		if (SCC[v] == -1)
			rDFS(v);
};

while (S.size()) {
	auto u = S.top(); S.pop();
	if (SCC[u] == -1)
		rDFS(u), c++;
}
