// LIS (lenth of the longest increasing subsequence)
// time complexity: O(n * log(n)), space: O(n)

vector<int> V(n);

vector<int> LIS(n + 1, INT32_MAX);
LIS[0] = INT32_MIN;
// for finding the longest non-decreasing subsequence, use *upper_bound:
for (auto v : V)
    *lower_bound(LIS.begin(), LIS.end(), v) = v;

int res = lower_bound(LIS.begin(), LIS.end(), INT32_MAX) - LIS.begin() - 1;	
