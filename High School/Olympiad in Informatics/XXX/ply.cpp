// Hubert Jastrzębski | XXX OI I (Płytkie nawiasowania) | 2022-11-11
// https://sio2.mimuw.edu.pl/c/oi30-1/p/ply/

#include <iostream>

using namespace std;

int main() {
    int n, H;
    string S;
    cin >> n >> H >> S;

    int res = 0;

    for (int i = 0, depth = 0; i < n; i++) {
        depth += (S[i] == '(' ? 1 : -1);
        if (depth < 0)
            depth = 1; // S[i] = '('
        else if (depth > H)
            depth -= 2, res++; // S[i] = ')'
    }

    cout << 2 * res;
}