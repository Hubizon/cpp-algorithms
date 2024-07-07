// Top-Bottom-Top Tree (update on segment, query on segment)
// time complexity: O(n * log(n)), query O(log (n)), space: O(n * log(n))

struct Value {
	int v = INT32_MIN;
};

Value operator+ (const Value& lhs, const Value& rhs) {
	return { max(lhs.v, rhs.v) };
}

struct Modifier {
	int m;
	bool active = false;
};

Modifier operator* (const Modifier& lhs, const Modifier& rhs) {
	if (!rhs.active) return lhs;
	return rhs;
}

Value operator* (const Value& val, const Modifier& mod) {
	if (mod.active) return { mod.m };
	return val;
}

struct Tree {
	struct Node {
		Value val;
		Modifier mod;
		operator Value() {
			return val * mod;
		}
	};

	int L = 1;
	vector<Node> T;

	Tree(int n) {
		while (L <= n) L *= 2;
		T.resize(2 * L);
	}

private:
	void update(int p, int q, const Modifier& mod, int tp, int tq, int v) {
		if (tq <= p || q <= tp) return;
		if (p <= tp && tq <= q) {
			T[v].mod = T[v].mod * mod;
			return;
		}
		T[2 * v].mod = T[2 * v].mod * T[v].mod;
		T[2 * v + 1].mod = T[2 * v + 1].mod * T[v].mod;
		T[v].mod = Modifier();
		int c = tp + (tq - tp) / 2;
		update(p, q, mod, tp, c, 2 * v);
		update(p, q, mod, c, tq, 2 * v + 1);
		T[v].val = T[2 * v] + T[2 * v + 1];
	}

public:
	void update(int p, int q, const Modifier& mod) { // [)
		update(p, q, mod, 0, L, 1);
	}

private:
	Value query(int p, int q, int tp, int tq, int v) {
		if (tq <= p || q <= tp) return Value();
		if (p <= tp && tq <= q)
			return T[v];
		int c = tp + (tq - tp) / 2;
		return (query(p, q, tp, c, 2 * v) + query(p, q, c, tq, 2 * v + 1)) * T[v].mod;
	}

public:
	Value query(int p, int q) { // [)
		return query(p, q, 0, L, 1);
	}
};
