// Hubert Jastrzębski | XXX OI II (Wirus) | 2023-02-14
// https://sio2.mimuw.edu.pl/c/oi30-2/p/wir/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void brute() {
    ll n, d;
    cin >> n >> d;

    deque<bool> Q;
    for (int i = 0; i < n; i++) {
        char x;
        cin >> x;
        Q.push_back(x == '1');
    }

    for (int i = 0; i < d; i++) {
        auto x = Q.front(); Q.pop_front();
        Q.push_back(x ^ Q.front());
    }

    while (Q.size()) {
        cout << Q.front(); Q.pop_front();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    brute();
}