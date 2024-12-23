// KMP Algorithm (finds pattern in a text)
// time complexity: O(n) space: O(n)

using namespace std;

vector<int> KMPSearch(const string& text, const string& pattern) {
    vector<int> lps = getLPS(pattern), Res;
    int n = text.size(), m = pattern.size(), i = 0, j = 0;

    while (i < n) {
        if (pattern[j] == text[i])
            i++, j++;
        if (j == m) {
            Res.push_back(i - j);
            j = lps[j];
        }
        else if (i < n && pattern[j] != text[i]) {
            if (j != 0) j = lps[j];
            else i++;
        }
    }
    return Res;
};
