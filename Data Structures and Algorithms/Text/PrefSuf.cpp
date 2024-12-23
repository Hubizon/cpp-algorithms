// the length of the longest prefix-suffix of the substring S[0..i]
// time complexity: O(n) space: O(n)

vector<int> getLPS(const string& S) {
    int n = S.size();
    vector<int> lps(n + 1);
    int t = lps[0] = -1;
    for (int i = 1; i <= n; i++) {
        while (t != -1 && S[t] != S[i - 1])
            t = lps[t];
        lps[i] = ++t;
    }
    return lps;
};
