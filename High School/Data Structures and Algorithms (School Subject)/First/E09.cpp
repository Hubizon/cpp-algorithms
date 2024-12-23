// Hubert Jastrzębski | Satori E09 (Wieże) | 2021-05-31
// https://satori.tcs.uj.edu.pl/contest/6459992/problems/6992306

#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int z;
    cin >> z;
    while (z--) {
        int n;
        cin >> n;
        vector<vector<bool>> board(n, vector<bool>(n));
        char sTile;
        for (auto& row : board) {
            for (auto&& tile : row) {
                cin >> sTile;
                tile = (sTile == 'o') ? false : true;
            }
        }

        long long max = 1LL << n, tempSize, tempK;
        vector<long long> DP(max, 0);
        DP[0] = 1;
        for (long long K = 1; K != max; K++) {
            tempSize = (bitset<64>(K).count()) - 1;
            for (int c = 0; c < n; c++) {
                tempK = K;
                if ((K >> c) & 1) {
                    tempK = K ^ (1LL << c);
                    if (board[tempSize][c])
                        DP[K] += DP[tempK];
                }
            }
        }

        cout << DP[max - 1] << '\n';
    }
}