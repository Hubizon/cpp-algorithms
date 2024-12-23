// Hubert Jastrzębski | Satori T02 (Naszyjnik) | 2022-03-07
// https://satori.tcs.uj.edu.pl/contest/7079339/problems/7423874

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int z;
    cin >> z;
    while (z--) {
        int n;
        cin >> n;

        string s1, s2;
        cin >> s1 >> s2;

        string S = s1 + s1;

        auto KPMSearch = [](string text, string pattern, vector<int> lps) {
          vector<int> Res;
          int n = text.size(), m = pattern.size(), i = 0, j = 0;
          while (i < n) {
              if (pattern[j] == text[i])
                  i++, j++;
              if (j == m) {
                  Res.push_back(i - j);
                  j = lps[j];
              }
              else if (i < n && pattern[j] != text[i]) {
                  if (j != 0) j = lps[j];
                  else i++;
              }
          }
          return Res;
        };

        auto getLPS = [](string S) {
          int n = S.size();
          vector<int> lps(n + 1);
          int t = lps.front() = -1;
          for (int i = 1; i <= n; i++) {
              while (t != -1 && S[t] != S[i - 1])
                  t = lps[t];
              lps[i] = ++t;
          }
          return lps;
        };

        string rs2 = string(s2.rbegin(), s2.rend());
        if (KPMSearch(S, s2, getLPS(s2)).size() || KPMSearch(S, rs2, getLPS(rs2)).size())
            cout << "IDENTYCZNE\n";
        else
            cout << "ROZNE\n";
    }
}