// Hubert Jastrzębski | XXX OI I (Kolorowy wąż) | 2022-11-11
// https://sio2.mimuw.edu.pl/c/oi30-1/p/kol/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, p, n;
    cin >> m >> p >> n;

    vector<vector<int>> P(m, vector<int>(m, -1));
    for (int i = 0; i < p; i++) {
        int w, k, c;
        cin >> w >> k >> c;
        P[w - 1][k - 1] = c;
    }

    vector<int> C = { 0 };
    vector<vector<int>> V(m, vector<int>(m, -1));
    V[0][0] = 0;

    int rcnt = 0;
    int wh = 0, kh = 0;
    while (n--) {
        char c;
        cin >> c;
        if (c == 'Z') {
            int w, k;
            cin >> w >> k;
            int v = rcnt - V[--w][--k];
            if (C.size() > v)
                cout << C[C.size() - v - 1] << '\n';
            else
                cout << "-1\n";
        }
        else {
            if (c == 'G') wh--;
            else if (c == 'D') wh++;
            else if (c == 'L') kh--;
            else if (c == 'P') kh++;

            V[wh][kh] = ++rcnt;

            auto& ppos = P[wh][kh];
            if (ppos != -1) {
                C.push_back(ppos);
                ppos = -1;
            }
        }
    }
}