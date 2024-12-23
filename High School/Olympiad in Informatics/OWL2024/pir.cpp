// Hubert Jastrzębski | PREOI / OWL 2024 (Piramida) | 2024-02-04
// https://sio2.staszic.waw.pl/c/preoi-owl-2024/p/pir/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int m = 2 * n - 1;
    vector<int> A(m);
    for (auto& a : A)
        cin >> a;

    auto check = [&](int x) -> bool {
      vector<int> B(m);
      for (int i = 0; i < m; i++)
          B[i] = (A[i] >= x);

      int top = B[0];
      for (int i = 1; i <= m / 2; i++) {
          if (B[m / 2 + i] == B[m / 2 + i - 1]) {
              top = B[m / 2 + i];
              break;
          }
          if (B[m / 2 - i] == B[m / 2 - i + 1]) {
              top = B[m / 2 - i];
              break;
          }
      }

      return top;
    };

    vector<int> ASS = A;
    sort(ASS.begin(), ASS.end());
    int start = 0, end = m;
    while (start < end) {
        int middle = start + (end - start) / 2;
        if (check(ASS[middle]))
            start = middle + 1;
        else
            end = middle;
    }

    cout << ASS[start - 1];
}