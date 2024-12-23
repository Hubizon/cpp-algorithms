// Hubert Jastrzębski | Satori T03 (Hymn) | 	2022-03-22
// https://satori.tcs.uj.edu.pl/contest/7079339/problems/7423898

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int z;
    cin >> z;
    while (z--) {
        string S;
        cin >> S;
        const int N = S.size();

        auto getLPS = [](string S) {
          int n = S.size();
          vector<int> lps(n + 1);
          int t = lps.front() = -1;
          for (int i = 0; i < n; i++) {
              while (t != -1 && S[t] != S[i])
                  t = lps[t];
              lps[i + 1] = ++t;
          }
          return lps;
        };

        vector<int> lps = getLPS(S);

        int n = N, res = n, prev = lps[n];
        while (prev != 0 && 2 * prev >= n) {
            if (N % prev == 0 && n % (n - prev) == 0) res = prev;
            prev = lps[n = prev];
        }

        cout << S.size() / res << '\n';
    }
}