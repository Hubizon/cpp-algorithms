// Hubert Jastrzębski | Krajowe Warsztaty Algorytmiczne PREOI KWA 2022 (Pamiętnik księżniczki Fiony) | 2022-02-12
// https://sio2.staszic.waw.pl/c/kwa-2022/p/pam/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string S, P;
    cin >> S >> P;
    int s = S.size(), p = P.size();
    string S1 = S + "69" + P;
    string S2 = string(S.rbegin(), S.rend()) + "69" + string(P.rbegin(), P.rend());
    int n = S1.size();

    auto Z = [](string S) {
      int n = S.size();
      vector<int> Z(n + 1);
      Z[0] = n;
      for (int i = 1, j = 0, k; i <= n; i += k, j = max(j - k, 0)) {
          while (i + j < n && S[j] == S[i + j]) j++;
          Z[i] = j;
          for (k = 1; k + Z[k] < j; k++)
              Z[i + k] = Z[k];
      }
      return Z;
    };

    vector<int> Z1 = Z(S1), Z2 = Z(S2);

    int res = 0;
    for (int i = n - p, j = n - s; i <= n - s; i++, j--)
        res = max(res, Z1[i] + Z2[j]);
    cout << (s - min(res, s));
}