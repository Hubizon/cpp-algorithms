// Hubert Jastrzębski | PREOI / OWL 2024 (Kręgle) | 2024-02-01
// https://sio2.staszic.waw.pl/c/preoi-owl-2024/p/krg/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <deque>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    unordered_map<int, int> AM, BM;
    vector<pair<int, int>> A(n), B(n);
    deque<pair<int, int>> Q;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        A[i] = { a, AM[a]++ };
        Q.push_back(A[i]);
    }

    for (int i = 0; i < n; i++) {
        int b;
        cin >> b;
        B[i] = { b, BM[b]++ };
    }

    string res;
    auto operation = [&](int k) {
      if (k == 0) {
          Q.push_back(Q.front());
          Q.pop_front();
          res += '0';
      }
      else {
          auto front = Q.front();
          Q.pop_front();
          Q.push_back(Q.front());
          Q.pop_front();
          Q.push_front(front);
          res += '1';
      }
    };

    while (Q[0] != B[n - 2])
        operation(0);

    while (Q[1] != B[n - 1])
        operation(1);

    int k = 2;
    for (int i = n - 3; i >= 0; i--) {
        int pos = 0;
        for (int j = 0; j < n; j++) {
            if (Q[j] == B[i]) {
                pos = j;
                break;
            }
        }

        int q = n - pos - 1;
        while (pos--)
            operation(0);
        while (q--)
            operation(1);
    }

    cout << res;
}