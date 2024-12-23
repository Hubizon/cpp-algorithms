// the length of the longest substring beggining in [i] that's also a prefix of the word S
// time complexity: O(n) space: O(n)

vector<int> getZ(const string& S) {
	int n = S.size();
	vector<int> Z(n);
	for (int i = 1, l = 0, r = 0; i < n; i++) {
		if (i <= r)
			Z[i] = min(r - i + 1, Z[i - l]);
		while (i + Z[i] < n && S[Z[i]] == S[i + Z[i]])
			Z[i]++;
		if (i + Z[i] - 1 > r)
			l = i, r = i + Z[i] - 1;
	}
	return Z;
}


// can be used e.g. for finding a pattern in a text:
string T, P; // text, pattern

string S = P + '#' + T; // (a special character that's not in the text)
vector<int> Z = getZ(S);

vector<int> R; // positions in the text where the pattern begins
for (int i = 0; i < Z.size(); i++)
	if (Z[i] == P.size())
		R.push_back(i - P.size() - 1);
		