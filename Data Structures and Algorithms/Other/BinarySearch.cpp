// Binary Search (first element that's greater (or equal) than x)
// time complexity: O(log(n)), space: O(1)

vector<int> V(n);

auto BinarySearch = [&](int start, int end, int x) { // [)
    while (start < end) {
        int middle = start + (end - start) / 2;
        if (V[middle] <= x) // < - lower_bound, <= - upper_bound
            start = middle + 1;
        else
            end = middle;
    }
    return start;
};
