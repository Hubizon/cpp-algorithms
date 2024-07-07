// Find Union
// time complexity: O(n), unify in O(log*(n)), space: O(n)

struct FindUnion {
	int componentsNum;
	vector<int> sizes, P;

	FindUnion(const int n) : sizes(n, 1), P(n) {
		componentsNum = n;
		for (int i = 0; i < n; i++) P[i] = i;
	}

	int find(int u) {
		if (P[u] != u) P[u] = find(P[u]);
		return P[u];
	}

	void unify(int u, int v) {
		int root1 = find(u), root2 = find(v);
		if (root1 == root2) return;
		if (sizes[root1] < sizes[root2])
			swap(root1, root2);
		sizes[root1] += sizes[root2];
		P[root2] = root1;
		componentsNum--;
	}

	bool connected(int u, int v) {
		return find(u) == find(v);
	}

	int componentSize(int u) {
		return sizes[find(u)];
	}
};
