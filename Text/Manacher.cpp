// Manacher Algorithm (find the longest palindromic substring)
// time complexity: O(n) space: O(n)

vector<int> Pal(const string& W) {
	string S = "#";
	for (auto& w : W)
		S += w, S += '#';

	int n = S.size();
	vector<int> R(n);
	R[0] = 1;

	for (int i = 1, j = 1, k; i < n; i += k, j -= k) {
		while (i - j >= 0 && i + j < n && S[i - j] == S[i + j])
			j++;
		R[i] = j;
		for (k = 1; k + R[i - k] < j; k++)
			R[i + k] = R[i - k];
	}

	return R;
}


string W; // text
int m = W.size();
vector<int> R = Pal(W);
vector<int> R1(m), R2(m); // even and odd palindrom rays
for (int i = 0; i < m; i++) {
	R1[i] = R[2 * i + 1] / 2;
	R2[i] = R[2 * i + 2] / 2;
}
