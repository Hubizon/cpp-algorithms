// Hubert Jastrzębski | Diamentowy Indeks AGH XVII 1 (Zgodny sąsiad) | 2023-10-21
// https://www.diament.agh.edu.pl/wp-content/uploads/2024/01/Etap_I_zadania_Informatyka.pdf

#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int MOD = 53;
const vector<int> P = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };

ll factor(int x) {
    ll res = 0;
    for (int i = 0; i < P.size(); i++)
        if (x % P[i] == 0)
            res = res | (1LL << i);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, a;
    cin >> n >> a;

    vector<ll> V(n * n), F(n * n);
    F[0] = factor(V[0] = a);

    for (int i = 1; i < n * n; i++)
        F[i] = factor(V[i] = (3 * V[i - 1]) % MOD);

    int res = 0;
    for (int i = 0; i < n * n; i++) {
        bool add = false;
        if (!add && i >= n)
            add = (F[i] == F[i - n]);
        if (!add && i < n * n - n)
            add = (F[i] == F[i + n]);
        if (!add && i % n != 0)
            add = (F[i] == F[i - 1]);
        if (!add && i % n != n - 1)
            add = (F[i] == F[i + 1]);
        res += add;
    }

    cout << res;
}