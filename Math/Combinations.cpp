// generate all k element combinations of a set
// time complexity: O((n, k) * n), space: O(n)

vector<int> V;
vector<int> combination;
void newton(int k, int offset = 0) {
    if (k == 0) {
        // do sth with the combination
        return;
    }
    for (int i = offset; i < V.size() - k; i++) {
        combination.push_back(V[i]);
        newton(k - 1, i + 1);
        combination.pop_back();
    }
}

// alternatively:
void newton(const vector<int>& V, const int k) {
    vector<bool> bitmask(V.size(), 0); 
    for (int i = 0; i < k; i++)
        bitmask[i] = 1;
 
    do {
        // do sth with the combination
    } while (prev_permutation(bitmask.begin(), bitmask.end()));
}

// combinations with repetitions:
vector<int> V;
vector<int> combination;
void newton(int k, int offset = 0) {
    if (k == 0) {
        // do sth with the combination
        return;
    }
    for (int i = offset; i < V.size(); i++) {
        combination.push_back(V[i]);
        newton(k - 1, i);
        combination.pop_back();
    }
}