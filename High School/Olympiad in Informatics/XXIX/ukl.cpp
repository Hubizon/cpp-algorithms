// Hubert Jastrzębski | XXIX OI I (Układanie kart) | 2021-10-27
// https://sio2.mimuw.edu.pl/c/oi29-1/p/ukl/

#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, m;
    cin >> n >> m;

    ll res = 0;

    // ile jeden segment (np 1... / 2...) ma kombinacji (n - 1)!
    ll times = 1;
    for (ll i = 2; i < n; i++) (times *= i) %= m;

    // ile będzie kolejnych wielkości bloczka
    int size = n + (n - 2);
    vector<ll> V(size, times);
    ll prev = 1, multi = n - 1;
    for (int i = 0; i < n - 2; i++) {
        V[i] = prev;
        V[i + n] = (times - prev + m) % m;
        (prev *= multi--) %= m;
    }

    // jaki bedzie wynik dla (n - 2) górnych warstw bloczków
    ll fac = 1;
    for (int i = 3; i <= n; i++) (fac *= i) %= m;
    ll next = (fac * n) % m;
    ll multiplierM = V[0], nextM = 1;
    for (int i = 1; i < n - 1; i++) {
        (res += next) %= m;
        (next += fac) %= m;
        (res -= ((n - 1) * multiplierM) % m - m) %= m;
        (multiplierM += V[nextM++]) %= m;
    }

    // dodawanie podstaw bloczka (bloczek bez n - 2 górnych)
    ll base = 0;
    for (int i = n - 2; i < size; i++) {
        (res += (V[i] * base) % m) %= m;
        (base += n - 1) %= m;
    }

    cout << res;
}