// Euclidean algorithm to find GCD	
// time complexity: O(log(n)) space: O(1)

int GCD(int a, int b) {
    if (b == 0) return a;
    return GCD(b, a % b);
};
