// RMQ (range min(/max) query)
// time complexity: O(n * log(n)), query O(1), space: O(n * log(n))

struct Value {
    int v = INT32_MAX;

    bool operator<(const Value& rhs) const& {
        return v < rhs.v;
    }
};

template <typename Value>
struct RMQ {
    int K;
    vector<vector<Value>> M;

    RMQ(const vector<Value>& m) : K(__lg(m.size()) + 1), M(K) {
        M[0] = m;

        for (int k = 1; k < K; k++)
            for (int i = 0; i < M[k - 1].size() - (1 << (k - 1)); i++)
                M[k].push_back(min(M[k - 1][i], M[k - 1][i + (1 << (k - 1))]));
    }

    Value query(int p, int q) { // [p, q)
        if (p >= q) return { };
        int k = __lg(q - p);
        return min(M[k][p], M[k][q - (1 << k)]);
    }
};
