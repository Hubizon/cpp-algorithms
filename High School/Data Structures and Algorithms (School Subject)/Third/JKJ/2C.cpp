// Hubert Jastrzębski | Satori 2C (Największy plus) | 2021-10-09
// https://satori.tcs.uj.edu.pl/contest/7079785/problems/7115821

#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int z;
    cin >> z;
    while (z--)
    {
        int n;
        cin >> n;

        vector<int> V(n);
        for (auto& v : V) cin >> v;

        auto is_possible = [&](int d) {
          int i = 0, j = 0;
          while (i + 2 * d + 1 <= n) {
              while (j < i + 2 * d + 1) {
                  if (V[j++] <= d) {
                      i = j;
                      break;
                  }
              }
              if (i != j) {
                  if (V[(j - i) / 2 + i] >= 2 * d + 1) return true;
                  i++;
              }
          }
          return false;
        };

        int a = 0, b = 400001;
        while (b > a) {
            int mid = (b - a) / 2 + a;
            if (is_possible(mid)) a = mid + 1;
            else b = mid;
        }

        cout << a - 1 << '\n';
    }
}