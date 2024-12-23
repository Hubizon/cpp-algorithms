// Hubert Jastrzębski | Satori E05 (Neon kontratakuje) | 2021-03-15
// https://satori.tcs.uj.edu.pl/contest/6459992/problems/6780875

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int a;
    cin >> a;
    while (a--)
    {
        string S1, S2;
        cin >> S1 >> S2;
        vector<int> to_fill(S2.size() + 1, 0);
        vector<vector<int>> LCS(S1.size() + 1, to_fill);

        for (int i = 1; i <= S1.size(); i++) {
            for (int j = 1; j <= S2.size(); j++) {
                if (S1[i - 1] == S2[j - 1])
                    LCS[i][j] = LCS[i - 1][j - 1] + 1;
                else
                    LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
            }
        }
        cout << LCS[S1.size()][S2.size()] << '\n';

        string result = "";
        int i = S1.size(), j = S2.size();
        while (i > 0 && j > 0) {
            if (LCS[i][j] != LCS[i - 1][j] && LCS[i][j] != LCS[i][j - 1]) {
                i--, j--;
                result += S2[j];
            }
            else if (LCS[i][j - 1] >= LCS[i - 1][j]) j--;
            else i--;
        }
        reverse(result.begin(), result.end());
        cout << result << '\n';
    }
}