// DFS (graph traversal)
// time complexity: O(n) [O(V + E)], space: O(n)

vector<vector<int>> G(n);
vector<bool> vis(n);

function<void(int)> DFS = [&](int u) {
    vis[u] = true;
    for (auto v : G[u])
        if (!vis[v])
            DFS(v);
};
