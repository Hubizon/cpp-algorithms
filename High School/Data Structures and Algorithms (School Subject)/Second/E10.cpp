// Hubert Jastrzębski | Satori E15 (Powrót neonu) | 2021-12-23
// https://satori.tcs.uj.edu.pl/contest/7079339/problems/7263048

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> LCS(string S1, string S2) {
    vector<int> LCS(S2.size() + 1);
    for (int i = 1; i <= S1.size(); i++) {
        for (int j = 1, a = 0, b; j <= S2.size(); j++) {
            if (S1[i - 1] == S2[j - 1])
                b = a + 1;
            else
                b = max(LCS[j], LCS[j - 1]);
            a = LCS[j];
            LCS[j] = b;
        }
    }
    return LCS;
}

string res(string S, string T) {
    if (S.size() == 1) {
        char s = S.front();
        for (auto& t : T)
            if (t == s)
                return { s };
        return "";
    }
    int middle = S.size() / 2;
    string S1 = S.substr(0, middle), S2 = S.substr(middle);
    vector<int> lcs1 = LCS(S1, T);
    string rS = S2, rT = T;
    reverse(rS.begin(), rS.end());
    reverse(rT.begin(), rT.end());
    vector<int> lcs2 = LCS(rS, rT);
    pair<int, int> maxCut = { -1, 0 };
    for (int i = 0; i <= T.size(); i++)
        if (lcs1[i] + lcs2[T.size() - i] > maxCut.first)
            maxCut = { lcs1[i] + lcs2[T.size() - i], i };
    return res(S1, T.substr(0, maxCut.second)) + res(S2, T.substr(maxCut.second));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int z;
    cin >> z;
    while (z--)
    {
        string S1, S2;
        cin >> S1 >> S2;
        string R = res(S1, S2);
        cout << R.size() << '\n' << R << '\n';
    }
}