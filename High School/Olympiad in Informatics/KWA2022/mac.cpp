// Hubert Jastrzębski | Krajowe Warsztaty Algorytmiczne PREOI KWA 2022 (Machina Macieja) | 2022-02-07
// https://sio2.staszic.waw.pl/c/kwa-2022/p/mac/

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

struct MinQ {
  deque<pair<int, int>> K;
  int A = 0;

  void push(int x) {
      int cnt = 0;
      while (!K.empty() && K.back().first >= x) {
          cnt += K.back().second + 1;
          K.pop_back();
      }
      K.push_back({ x, cnt });
  }

  void pop() {
      if (K.front().second == 0)
          K.pop_front();
      else
          K.front().second--;
  }

  int extreme() { // min / max
      return K.front().first;
  }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k, l;
    cin >> n >> m >> k >> l;

    vector<vector<int>> V(n, vector<int>(m));
    for (auto& v : V)
        for (auto& vv : v)
            cin >> vv;

    vector<vector<int>> MD(n, vector<int>(m));
    for (int j = 0; j < m; j++) {
        MinQ Q;
        for (int i = n - 1; i > n - k; i--) Q.push(V[i][j]);
        for (int i = n - k; i >= 0; i--) {
            Q.push(V[i][j]);
            MD[i][j] = Q.extreme();
            Q.pop();
        }
    }

    vector<vector<int>> R(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        MinQ Q;
        for (int j = m - 1; j > m - l; j--) Q.push(MD[i][j]);
        for (int j = m - l; j >= 0; j--) {
            Q.push(MD[i][j]);
            R[i][j] = Q.extreme();
            Q.pop();
        }
    }

    for (int i = 0; i <= n - k; i++) {
        for (int j = 0; j <= m - l; j++)
            cout << R[i][j] << ' ';
        cout << '\n';
    }
}