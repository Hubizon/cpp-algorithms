// Hubert Jastrzębski | XXXI OI I (CzatBBB) | 2023-11-11
// https://sio2.mimuw.edu.pl/c/oi31-1/p/cza/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef array<ll, 4> Hashes;

const int hash_n = 4;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, k, a, b;
    cin >> n >> k >> a >> b;

    string S;
    cin >> S;

    const Hashes PRIMES = { 137, 181, 211, 239 };
    const ll MOD = 1e9 + 100501;

    int deg = 4 * n + 69;
    vector<Hashes> P(deg);
    vector<ll> xs(hash_n, 1);
    for (int i = 0; i < deg; i++)
        for (int j = 0; j < hash_n; j++)
            P[i][j] = ((xs[j] *= PRIMES[j]) %= MOD);

    Hashes hash = { 0, 0, 0, 0 };
    for (int i = 0; i < k; i++)
        for (int j = 0; j < hash_n; j++)
            (hash[j] += (S[i] * P[i][j])) %= MOD;

    auto getComparableHash = [&](int i) {
      Hashes ssHash = hash;
      for (int j = 0; j < hash_n; j++)
          (ssHash[j] *= P[deg - i - k][j]) %= MOD;
      return ssHash;
    };

    map<Hashes, map<char, int>> MS;
    for (int i = k; i < n; i++) {
        MS[getComparableHash(i - k)][S[i]]++;
        for (int j = 0; j < hash_n; j++)
            hash[j] = (hash[j] - (S[i - k] * P[i - k][j]) % MOD + MOD + (S[i] * P[i][j])) % MOD;
    }

    map<Hashes, char> M;
    for (const auto& [k, v] : MS) {
        char resc = 'a';
        int rescnt = 0;
        for (const auto& [c, cnt] : v)
            if (cnt > rescnt || (cnt == rescnt && c < resc))
                resc = c, rescnt = cnt;
        M[k] = resc;
    }

    map<Hashes, int> CycleM;
    int ix = n, pos = -1;
    while (true) {
        auto h = getComparableHash(ix - k);
        if (ix >= n + k) {
            if (CycleM.count(h)) {
                pos = CycleM[h];
                break;
            }
            CycleM[h] = ix;
        }

        auto hm = M.find(h);
        if (hm != M.end())
            S += hm->second;
        else
            S += 'a';

        for (int j = 0; j < hash_n; j++)
            hash[j] = (hash[j] - (S[ix - k] * P[ix - k][j]) % MOD + MOD + (S[ix] * P[ix][j])) % MOD;
        ++ix;
    }

    --a, --b;
    if (b < S.size())
        cout << S.substr(a, b - a + 1);
    else {
        n = pos - k;
        string cycle = S.substr(n, S.size() - n - k);
        int clen = cycle.size();

        if (a < n) {
            cout << S.substr(a, n - a);
            a = n;
        }

        a -= n, b -= n;
        b -= clen * (a / clen); a %= clen;

        if (b < clen)
            cout << cycle.substr(a, b - a + 1);
        else {
            cout << cycle.substr(a);
            for (int i = 0; i < b / clen - 1; i++)
                cout << cycle;
            cout << cycle.substr(0, b % clen + 1);
        }
    }
}