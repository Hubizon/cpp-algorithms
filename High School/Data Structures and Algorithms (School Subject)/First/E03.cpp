// Hubert Jastrzębski | Satori E03 (Diamenty) | 2021-03-08
// https://satori.tcs.uj.edu.pl/contest/6459992/problems/6755989

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
string read_path(const vector<vector<int>>&, const int&, const int&);

int main()
{
    int a;
    cin >> a;
    while (a--)
    {
        int w, h, result = 0;
        string moves = "";
        cin >> w >> h;
        vector<int> to_fill(w, 0);
        vector<vector<int>> V(h, to_fill);
        vector<vector<int>> dp(h, to_fill);
        for (auto& v : V)
            for (auto& vv : v)
                cin >> vv;

        dp[0][0] = V[0][0];
        for (int i = 1; i < h; i++)
            dp[i][0] = dp[i - 1][0] + V[i][0];
        for (int j = 1; j < w; j++)
            dp[0][j] = dp[0][j - 1] + V[0][j];
        for (int i = 1; i < h; i++)
            for (int j = 1; j < w; j++)
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + V[i][j];
        cout << dp[h - 1][w - 1] << ' ';

        moves = read_path(dp, w, h);
        for (int i = moves.size(); i--;)
            cout << moves[i];
        cout << '\n';
    }
}

string read_path(const vector<vector<int>>& dp, const int& w, const int& h)
{
    string to_return = "";
    int i = h - 1, j = w - 1;
    for (int n = w + h - 2; n--;)
    {
        if (i == 0)
            to_return += '>';
        else if (j == 0)
            to_return += 'v';
        else {
            if (dp[i - 1][j] > dp[i][j - 1]) {
                to_return += 'v';
                i--;
            }
            else {
                to_return += '>';
                j--;
            }
        }
    }
    return to_return;
}