// Segment Tree (update on segment, query on segment +/+, +/min, min/min)
// time complexity: O(n * log(n)), query O(log (n)), space: O(n * log(n))

struct Value {
	int v = INT32_MIN;
};

Value operator+(const Value& lhs, const Value& rhs) {
	return { max(lhs.v, rhs.v) };
}

struct Modifier {
	int m = 0;
};

Modifier operator*(const Modifier& lhs, const Modifier& rhs) {
	return { lhs.m + rhs.m };
}

Value operator*(const Value& lhs, const Modifier& rhs) {
	return { lhs.v + rhs.m };
}

template<typename Value, typename Modifier>
struct Tree {
	struct Node {
		Value value;
		Modifier modifier;
		operator Value() {
			return value * modifier;
		}
	};

	int L = 1;
	vector<Node> T;

	Tree(const int n) {
		while (L <= n) L *= 2;
		T = vector<Node>(2 * L);
	}
	
	Tree(const vector<Value>& V) {
		while (L <= V.size()) L *= 2;
		T = vector<Node>(2 * L);
		for (int i = 0; i < V.size(); i++)
			T[i + L].value = V[i];
		for (int i = L - 1; i > 0; i--)
			T[i].value = T[2 * i] + T[2 * i + 1];
	}

	void update(int p, int q, const Modifier& modifier) { // [p, q)
		if (p >= q) return;
		p += L, q += L;
		T[p].modifier = T[p].modifier * modifier;
		while (p / 2 != q / 2) {
			if (p % 2 == 0) T[p + 1].modifier = T[p + 1].modifier * modifier;
			if (q % 2 == 1) T[q - 1].modifier = T[q - 1].modifier * modifier;
			p /= 2, q /= 2;
			T[p].value = T[2 * p] + T[2 * p + 1];
			T[q].value = T[2 * q] + T[2 * q + 1];
		}
		while (p /= 2)
			T[p].value = T[2 * p] + T[2 * p + 1];
	}

	Value query(int p, int q) { // [p, q)
		if (p >= q) return { };
		p += L, q += L;
		Value resL = T[p], resR = { };
		while (p / 2 != q / 2) {
			if (p % 2 == 0) resL = resL + T[p + 1];
			if (q % 2 == 1) resR = T[q - 1] + resR;
			p /= 2, q /= 2;
			resL = resL * T[p].modifier;
			resR = resR * T[q].modifier;
		}
		resL = resL + resR;
		while (p /= 2)
			resL = resL * T[p].modifier;
		return resL;
	}
};
