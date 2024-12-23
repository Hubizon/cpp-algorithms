// Hubert Jastrzębski | PREOI / OWL 2024 (Osobliwy Sklep) | 2024-02-04
// https://sio2.staszic.waw.pl/c/preoi-owl-2024/p/tmp/

#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> A(n);
    for (auto& a : A)
        cin >> a;

    sort(A.rbegin(), A.rend());

    if (A.front() != n) {
        cout << "NIE";
        exit(0);
    }

    function<bool(vector<int>, vector<int>, vector<int>)> fun = [&](vector<int> P, vector<int> Ava, vector<int> C) {
      if (P.size() == 0) {
          if (C.empty()) {
              if (Ava.empty())
                  return true;
              return false;
          }
          return fun(C, Ava, { });
      }

      if (P.front() == 1) {
          P = vector<int>(P.begin() + 1, P.end());
          return fun(P, Ava, C);
      }

      vector<set<vector<int>>> DP(P.front());
      // DP[s] - jakimi wierzchołkami da się uzyskać sume 's'

      for (int v = 0; v < Ava.size(); v++) {
          for (int s = P.front() - 1; s >= 1; s--) {
              if (s - Ava[v] == 0)
                  DP[s].insert({ Ava[v] });
              else if (s - Ava[v] > 0 && DP[s - Ava[v]].size()) {
                  for (auto dps : DP[s - Ava[v]]) {
                      dps.push_back(Ava[v]);
                      DP[s].insert(dps);
                  }
              }
          }
      }

      vector<int> TAva(n + 1);
      for (auto& ava : Ava)
          TAva[ava]++;

      P = vector<int>(P.begin() + 1, P.end());
      for (auto dp : DP.back()) {
          if (dp.size() == 1) continue;

          for (auto v : dp)
              TAva[v]--;

          vector<int> nAva;
          for (int i = TAva.size() - 1; i >= 1; i--)
              for (int j = 0; j < TAva[i]; j++)
                  nAva.push_back(i);


          for (auto v : dp)
              TAva[v]++;

          for (auto c : C)
              dp.push_back(c);

          if (fun(P, nAva, dp))
              return true;
      }

      return false;
    };

    vector<int> toC;
    for (int i = 1; i < n; i++)
        toC.push_back(A[i]);

    cout << (fun({ A[0] }, toC, { }) ? "TAK" : "NIE");
}