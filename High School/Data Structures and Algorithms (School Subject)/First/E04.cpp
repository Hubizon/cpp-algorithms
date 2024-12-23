// Hubert Jastrzębski | Satori E04 (Neon) | 2021-03-22
// https://satori.tcs.uj.edu.pl/contest/6459992/problems/6780847

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

        vector<int> LCS(S2.size() + 1);
        int a = 0, b = 0;
        for (int i = 1; i <= S1.size(); i++) {
            for (int j = 1; j <= S2.size(); j++) {
                if (S1[i - 1] == S2[j - 1])
                    a = b + 1;
                else
                    a = max(LCS[j - 1], LCS[j]);
                b = LCS[j];
                LCS[j] = a;
            }
            b = 0;
        }
        cout << LCS.back() << '\n';
    }
}