// topological sort in DAG
// time complexity: O(n) [O(V + E)], space: O(n)

vector<vector<int>> G(n);
vector<bool> vis(n);
vector<int> R; R.reserve(n);

function<void(int)> TSort = [&](int u) {
    vis[u] = true;
    for (auto v : G[u])
        if (!vis[v])
            TSort(v);
    R.push_back(u);
};

for (int i = 0; i < n; i++)
    if (!vis[i])
        TSort(i);

reverse(R.begin(), R.end());
