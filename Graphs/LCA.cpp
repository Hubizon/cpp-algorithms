// LCA (lowest common ancestor in a tree offline)
// time complexity: O(n * log(n)), query O(1), space: O(n * log(n))

struct Value {
    int v = -1, d = INT32_MAX;

    bool operator<(const Value& rhs) const& {
        return d < rhs.d;
    }
};

template<typename Value>
struct LCA {
    vector<vector<int>> G;
    vector<Value> E; // vertex, depth
    vector<int> F;
    RMQ<Value> rmq;

    LCA(const vector<vector<int>>& G, const int root = 0) : G(G), F(G.size(), -1) {
        DFS(root);
        rmq = RMQ<Value>(E);
    }

    void DFS(int u, int d = 0) {
        F[u] = E.size();
        E.push_back({ u, d });
        for (auto& v : G[u]) {
            if (F[v] != -1) continue;
            DFS(v, d + 1);
            E.push_back({ u, d });
        }
    }

    int query(int u, int v) {
        auto [fu, fv] = minmax(F[u], F[v]);
        return rmq.query(fu, fv + 1).v;
    }
};
