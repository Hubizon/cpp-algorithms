// Hubert Jastrzębski | PREOI / OWL 2024 (Sztuczka) | 2024-01-29
// https://sio2.staszic.waw.pl/c/preoi-owl-2024/p/szt/

#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

vector<ll> CompPermutations(const vector<ll>& A, const vector<ll>& B) {
    int n = A.size();
    vector<ll> R(n);
    for (int i = 0; i < n; i++)
        R[i] = A[B[i]];
    return R;
}

vector<ll> fastPow(vector<ll> P, ll k) {
    vector<ll> out(P.size());
    for (int i = 0; i < P.size(); i++)
        out[i] = i;
    while (k) {
        if (k % 2 == 1)
            out = CompPermutations(out, P);
        k /= 2;
        P = CompPermutations(P, P);
    }
    return out;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<ll> A(n);
    for (auto& a : A)
        cin >> a;

    vector<ll> B(n - 1);
    for (int i = 0; i < n - 1; i++)
        B[i] = A[i + 1] - A[i];

    vector<ll> P(n - 1);
    for (int i = 0; i < n - 1; i++)
        P[i] = i;

    ll q, m;
    cin >> q >> m;
    while (q--) {
        ll s;
        cin >> s;
        swap(P[s - 2], P[s - 1]);
    }

    P = fastPow(P, m);

    vector<ll> BP(n - 1);
    for (int i = 0; i < n - 1; i++)
        BP[i] = B[P[i]];

    ll prev = A[0];
    for (auto bp : BP) {
        cout << prev << ' ';
        prev += bp;
    }
    cout << prev;
}