// Hashing
// time complexity: O(n) space: O(n)

string S;
int n = S.size();

const long long PRIME1 = 131, PRIME2 = 151;
const long long MOD = 1e9 + 1011;

vector<long long> P1(n), P2(n);
for (long long i = 0, x1 = 1, x2 = 1; i < n; i++) {
    P1[i] = ((x1 *= PRIME1) %= MOD);
    P2[i] = ((x2 *= PRIME2) %= MOD);
}

vector<long long> HPre1(n + 1), HPre2(n + 1);
for (int i = 0; i < n; i++) {
    HPre1[i + 1] = (HPre1[i] + (S[i] * P1[i])) % MOD;
    HPre2[i + 1] = (HPre2[i] + (S[i] * P2[i])) % MOD;
}

auto getComparableHash = [&](int i, int l) {
    array<long long, 2> ssHash = { (HPre1[i + l] - HPre1[i] + MOD) % MOD,
        (HPre2[i + l] - HPre2[i] + MOD) % MOD };
    (ssHash[0] *= P1[n - i - l]) %= MOD, (ssHash[1] *= P2[n - i - l]) %= MOD;
    return ssHash;
};

// check whether substring S[i ... i + l - 1] = S[j ... j + l - 1]
auto check = [&](int i, int j, int l) {
    return getComparableHash(i, l) == getComparableHash(j, l);
};
