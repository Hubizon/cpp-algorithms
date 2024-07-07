// returns a^k % q (you can also exponentiate e.g. matrices)
// time complexity: O(log(n)), space: O(1)

int fastPower(int a, int k, int q) {
    int out = 1;
    while (k) {
        if (k & 1) (out *= a) %= q;
        k >>= 1;
        (a *= a) %= q;
    }
    return out;
};
