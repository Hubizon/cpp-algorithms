// Hubert Jastrzębski | Satori T04 (Mantra) | 2022-03-14
// https://satori.tcs.uj.edu.pl/contest/7079339/problems/7423926

#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    auto getZ = [](const string& S) {
      int n = S.size();
      vector<int> Z(n + 1); Z[0] = n;
      for (int i = 1, j = 0, k; i <= n; i += k, j = max(j - k, 0)) {
          while (i + j < n && S[j] == S[i + j]) j++;
          Z[i] = j;
          for (k = 1; k + Z[k] < j; k++)
              Z[i + k] = Z[k];
      }
      return Z;
    };

    int z; // cba#abcbacb
    cin >> z;
    while (z--) {
        int w, n;
        string P, T;
        cin >> w >> P >> n >> T;
        vector<int> Z = getZ(P + '#' + T);
        vector<int> revZ = getZ(string(P.rbegin(), P.rend()) + '#' + string(T.rbegin(), T.rend()));

        vector<int> R(n + 1);
        for (int i = 0; i <= n; i++) {
            int a = w + 1 + i, b = revZ.size() - i - 1;
            if (Z[a] + revZ[b] >= w)
                R[i - revZ[b]] += 1, R[i + Z[a] - w + 1] -= 1;
        }

        partial_sum(R.begin(), R.end(), R.begin());

        vector<int> Res;
        for (int i = 0; i < R.size(); i++)
            if (R[i] > 0) Res.push_back(i);

        cout << Res.size();
        for (auto& res : Res) cout << ' ' << res;
        cout << '\n';
    }
}