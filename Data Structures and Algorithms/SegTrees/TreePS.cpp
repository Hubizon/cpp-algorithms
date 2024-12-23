// Segment Tree (update on point, query on segment)
// time complexity: O(n * log(n)), query O(log (n)), space: O(n * log(n))

struct Value {
    int v = INT32_MIN;
};

Value operator+(const Value& lhs, const Value& rhs) {
    return { max(lhs.v, rhs.v) };
}

Value operator*(const Value& lhs, const Value& rhs) {
    return rhs;
}

template <typename Value>
struct Tree {
    int L = 1;
    vector<Value> T;

    Tree(const int n) {
        while (L <= n) L *= 2;
        T = vector<Value>(2 * L);
    }

    Tree(const vector<Value>& V) {
        while (L <= V.size()) L *= 2;
        T = vector<Value>(2 * L);
        for (int i = 0; i < V.size(); i++)
            T[i + L] = V[i];
        for (int i = L - 1; i > 0; i--)
            T[i] = T[2 * i] + T[2 * i + 1];
    }

    void update(int i, const Value& x) {
        i += L;
        T[i] = T[i] * x;
        while (i /= 2)
            T[i] = T[2 * i] + T[2 * i + 1];
    }

    Value query(int p, int q) { // [p, q)
        if ((p += L) >= (q += L)) return { };
        Value resL = T[p], resR = { };
        while (p / 2 != q / 2) {
            if (p % 2 == 0) resL = resL + T[p + 1];
            if (q % 2 == 1) resR = T[q - 1] + resR;
            p /= 2, q /= 2;
        }
        return resL + resR;
    }
};
