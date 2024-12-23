// Hubert Jastrzębski | XXIX OI I (Impreza krasnali) | 2021-11-21
// https://sio2.mimuw.edu.pl/c/oi29-1/p/imp/

#include <iostream>
#include <functional>
#include <vector>

using namespace std;

typedef long long ll;
constexpr int MODULO = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; // 2 <= n <= 100,000
    cin >> n;

    // wypełnienie wartości z wejścia
    vector<int> H(n); // 1 <= h <= n
    for (auto& h : H)  cin >> h;

    // sprawdzenie czy sprzeczne dane 1)
    vector<int> prev(n + 1, -1);
    for (int i = 0; i < n; i++) {
        auto& pos = prev[H[i]];
        // czy ta czapka już się pojawiła? jeśli była dokładnie 2 krasnale wcześniej to nie ma sprzeczności
        if (pos != -1 && pos != i - 2) {
            cout << 0;
            return 0;
        }
        if (pos == -1) pos = i;
    }

    // funkcja rekurencyjna do ustawiania stałych czapek
    bool is_end = false;
    vector<int> V(n);
    function<void(int, int)> setHat = [&](int pos, int val) {
      if (V[pos] != 0) {
          if (V[pos] != val) is_end = true;
          return;
      }
      V[pos] = val;
      if (pos < n - 2 && H[pos + 1] != val) setHat(pos + 2, H[pos + 1]);
      if (pos > 1 && H[pos - 1] != val) setHat(pos - 2, H[pos - 1]);
    };

    // ustawienie stałych czapek
    setHat(1, H.front());
    setHat(n - 2, H.back());
    for (int i = 2; i < n - 2; i++) {
        if (H[i - 1] == H[i + 1])
            setHat(i, H[i - 1]);
    }

    // sprawdzenie czy nie wywaliło się w funkcji rekurencyjnej
    if (is_end) {
        cout << 0;
        return 0;
    }

    // sprawdzenie czy sprzeczne dane 2)
    for (int i = 1; i < n - 1; i++) {
        if (V[i - 1] != 0 && V[i + 1] != 0 && V[i - 1] != H[i] && V[i + 1] != H[i]) {
            cout << 0;
            return 0;
        }
    }

    // funkcja do dodawania segmentu do wyniku
    ll res = 1, tempL = 0, sum = 0;
    auto addSegment = [&]() {
      (res *= tempL) %= MODULO;
      tempL = 0;
      sum++;
    };

    // obliczanie wyniku dla parzystych (0, 2, 4, ...):
    for (int i = 0; i < n; i += 2) {
        if (V[i] == 0) tempL++;
        else if (tempL > 0) addSegment();
    }
    if (tempL > 0) addSegment();

    // obliczanie wyniku dla nieparzystych (1, 3, 5, ...):
    for (int i = 1; i < n; i += 2) {
        if (V[i] == 0) tempL++;
        else if (tempL > 0) addSegment();
    }
    if (tempL > 0) addSegment();

    // obliczanie ostatecznego wyniku
    ll fac = 1;
    for (int i = 2; i <= sum; i++)
        (fac *= i) %= MODULO;
    (res *= fac) %= MODULO;

    cout << res;
}