// Hubert Jastrzębski | XXX OI II (Drwale) | 2023-02-16
// https://sio2.mimuw.edu.pl/c/oi30-2/p/drw/

#include <bits/stdc++.h>

using namespace std;

void brute() {
    int n;
    cin >> n;
    vector<int> V(n);
    for (auto& v : V)
        cin >> v;

    int res = 0;
    do {
        vector<int> TV = V;
        int t1 = 0, t2 = 0;
        while (TV.size()) {
            auto u = TV.back(); TV.pop_back();
            if (t1 <= t2) t1 += u;
            else t2 += u;
        }
        res = max({ res, t1, t2 });
    } while(next_permutation(V.begin(), V.end()));

    cout << res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    brute();
}