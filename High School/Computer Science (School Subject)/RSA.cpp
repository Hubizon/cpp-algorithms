// Hubert Jastrzębski | Informatyka (RSA) | 2021-02-07
// https://classroom.google.com/u/1/c/MTkwNjU0OTAwNjgy/a/NDMxNzkxODEzNjcy/details

#include <iostream>
#include <functional>
#include <fstream>
#include <numeric>
#include <string>
#include <random>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

typedef long long ll;

constexpr int aSize = 128; 
constexpr int powOfASize[] = { 1, aSize, aSize * aSize, aSize * aSize * aSize };
const string inFile = "jawny.txt";
const string outFileEnc = "szyfrogram.txt";
const string outFileDec = "odszyfrowany.txt";

auto quickPower = [](ll a, ll k, ll q) {
    ll out = 1;
    while (k) {
        if (k & 1LL) (out *= a) %= q;
        k >>= 1;
        (a *= a) %= q;
    }
    return out;
};

auto encrypt = [](ll x, pair<ll, ll> PUBLIC_KEY) {
    auto [n, e] = PUBLIC_KEY;
    return quickPower(x, e, n);
};

auto decrypt = [](ll x, pair<ll, ll> PRIVATE_KEY) {
    auto [n, d] = PRIVATE_KEY;
    return quickPower(x, d, n);
};

int main()
{
    // RSA:
    const int m = 32000;
    vector<bool> S(m + 1);
    vector<int> P;

    for (int i = 2; i * i <= m; i++)
        if (!S[i])
            for (int j = i * i; j <= m; j += i)
                S[j] = true;
    for (int i = powOfASize[2] + 1; i <= m; i++)
        if (!S[i]) P.push_back(i);

    mt19937_64 rng(steady_clock::now().time_since_epoch().count());
    ll p1 = P[uniform_int_distribution<int>(0, P.size() - 1)(rng)];
    ll p2 = P[uniform_int_distribution<int>(0, P.size() - 1)(rng)];
    ll n = p1 * p2, phi = (p1 - 1) * (p2 - 1); // nie powinno by� phi = lcm((p1 - 1), (p2 - 1)); ?

    ll e;
    do {
        e = uniform_int_distribution<long long>(2, phi - 1)(rng);
    } while (gcd(phi, e) != 1);

    function<pair<ll, ll>(ll, ll)> EEUCLID = [&EEUCLID](ll a, ll b) -> pair<ll, ll> {
        if (b == 0) return { 1, 0 };
        auto [ap, bp] = EEUCLID(b, a % b);
        return { bp, ap - bp * (a / b) };
    };

    ll d = EEUCLID(e, phi).first;
    if (d < 0) d += phi;

    pair<ll, ll> PUBLIC_KEY = { n, e };
    pair<ll, ll> PRIVATE_KEY = { n, d };

    // zaszyfrowywanie:
    ifstream in(inFile);
    ofstream outEnc(outFileEnc);
    string T;
    while (getline(in, T)) {
        for (int i = 0; i < (T.size() + 3) / 4; i++) {
            string S = string(T.begin() + i * 4, ((i + 1) * 4 >= T.size() ? T.end() : T.begin() + (i + 1) * 4));
            ll x = 0, j = S.size() - 1;
            for (auto& s : S)
                x += powOfASize[j--] * s;

            ll res = encrypt(x, PUBLIC_KEY);
            outEnc << res << ' ';
        }
        outEnc << '\n';
    }

    in.close(), outEnc.close();

    // odszyfrowywanie:
    in.open(outFileEnc);
    ofstream outDec(outFileDec);
    while (getline(in, T)) {
        int prev = 0;
        auto f = T.find(' ');
        while (f != string::npos) {
            string X = T.substr(prev, f);
            prev = f + 1;
            f = T.find(' ', prev);
            if (X.empty()) continue;

            ll res = stoll(X);
            ll x = decrypt(res, PRIVATE_KEY);

            string S;
            x *= aSize;
            while (x /= aSize) {
                S += (char)(x % aSize);
            }
            outDec << string(S.rbegin(), S.rend());
        }
        outDec << '\n';
    }

    in.close(), outDec.close();
}