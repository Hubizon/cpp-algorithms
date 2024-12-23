// Hubert Jastrzębski | Satori GRZ (Grzyby) | 2022-08-29
// https://satori.tcs.uj.edu.pl/contest/1870276/problems/6102979

#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

constexpr int SIZE = 4010;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int z;
    cin >> z;
    while (z--) {
        int n, x;
        string S;
        cin >> n >> x >> S;

        vector<int> W(n);
        for (auto& w : W) cin >> w;

        const int move = SIZE - (2 * x + 1);
        bitset<SIZE> dp; dp[x] = 1;
        for (int i = 0; i < n; i++) {
            auto w = W[i];
            if (S[i] == 'B') dp >>= w;
            else dp |= (dp << w);
            dp <<= move;
            dp >>= move;
        }

        cout << (dp.any() ? "TAK\n" : "NIE\n");
    }
}