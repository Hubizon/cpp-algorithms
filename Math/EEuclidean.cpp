// Extended Euclidean Algorithm:
// returns such x, y that ax + by = gcd(a, b)
// if a and b are coprime, then x is the modular multiplicative inverse of a modulo b,
//                         and y is the modular multiplicative inverse of b modulo a
// time complexity: O(log(n)) space: O(1)

pair<int, int> EEUCLID(int a, int b) {
	if (b == 0) return { 1, 0 };
	auto [ap, bp] = EEUCLID(b, a % b);
	return { bp, ap - bp * (a / b) };
};
