// Hubert Jastrzębski | XXIX OI I (Druk) | 2021-11-21
// https://sio2.mimuw.edu.pl/c/oi29-1/p/dru/

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<string> V(n);
    for (auto& v : V) cin >> v;

    // znajdywanie ilości różnych literek
    unordered_map<char, int> DifC;
    for (auto& v : V) {
        for (auto& vv : v)
            DifC[vv]++;
    }

    // znajdywanie kandydatów do wyniku (dzielniki n * m, nie większe od max(n, m)):
    vector<int> Div;
    for (int i = 1; i <= max(n, m); i++) {
        if (n % i == 0 || m % i == 0)
            Div.push_back(i);
    }

    // rozważenie przypadku w którym wszystkie litery są takie same
    if (DifC.size() == 1) {
        cout << Div.size() << '\n';
        for (auto& div : Div)
            cout << div << ' ';
        return 0;
    }

    // funkcja do sprawdzania którzy z kandydatów mogą być ustawieni poziomo i pionowo (według ilości literek)
    const int totalChars = n * m;
    const char lastChar = V.back().back();
    auto preCheck = [&](bool isHorizontal) {
      unordered_map<int, string> direction; // kandydaci na wzór umieszczony w poziomie / pionie
      unordered_map<char, int> dDifC; // ilość poszczególnych literek (dodawana jedna za kazdym razem)
      string tPattern = ""; // aktualny wzór (zwiększany o 1 z każdym powtórzeniem pętli)
      int l = isHorizontal ? m : n;
      tPattern.reserve(l);
      for (int i = 1; i <= l; i++) {
          auto c = isHorizontal ? V[0][i - 1] : V[i - 1][0];
          tPattern += c;
          dDifC[c]++;
          // jeśli dane i jest kandydatem i zgadza sie ostatnia litera:
          if ((n % i == 0 || m % i == 0) && tPattern.back() == lastChar) {
              // sprawdzamy czy ten wzór ma odpowiednia ilość każdej z liter:
              const int patternCnt = totalChars / i; // ilość wzorów na planszy
              if (DifC.size() == dDifC.size()) {
                  bool is_ok = true;
                  for (auto& [letter, count] : DifC) {
                      if (patternCnt * dDifC[letter] != count) {
                          is_ok = false;
                          break;
                      }
                  }
                  if (is_ok) direction[i] = tPattern;
              }
          }
      }
      return direction;
    };

    // sprawdzanie kandydatów poziomo i pionowo:
    unordered_map<int, string> horizontal = preCheck(true);
    unordered_map<int, string> vertical = preCheck(false);

    // funkcja do sprawdzenia, czy da się zapełnić planszę pewnym wzorem
    auto check = [&](vector<vector<bool>>& isFilled, string& pattern) {
      int div = pattern.size();
      // rozpatrujemy kazdą literę osobno:
      for (int i = 0; i < n; i++) {
          for (int j = 0; j < m; j++) {
              // czy ustaliliśmy już dla niej wartość
              if (!isFilled[i][j]) {
                  // czy nasz wzór mieści się na prawo
                  if (j + div <= m) {
                      // sprawdzenie czy wzór tam pasuje:
                      int k;
                      for (k = j; k < j + div; k++)
                          if (V[i][k] != pattern[k - j] || isFilled[i][k]) break;
                      // jeśli pasuje, to uzupełniamy i idziemy dalej
                      if (k == j + div) {
                          for (k = j; k < j + div; k++)
                              isFilled[i][k] = true;
                          continue;
                      }
                  }
                  // nie da się uzupelnić na prawo, więc patrzymy czy nasz wzór mieści sie w dół
                  if (i + div <= n) {
                      // sprawdzenie czy wzór tam pasuje:
                      int k;
                      for (k = i; k < i + div; k++)
                          if (V[k][j] != pattern[k - i]) break;
                      // jeśli pasuje, to uzupełniamy i idziemy dalej
                      if (k == i + div) {
                          for (k = i; k < i + div; k++)
                              isFilled[k][j] = true;
                          continue;
                      }
                  }
                  // jeśli nie da sie uzupelnić ani na prawo, ani na lewo, to wzór jest zły
                  return false;
              }
          }
      }
      // w przeciwnym wypadku wzór jest dobry
      return true;
    };

    // sprawdzanie poprawności każdego dzielnika:
    vector<int> Res;
    for (auto& div : Div) {
        // pierwszy wzór ustawiamy na prawo (sprawdzamy czy się mieści i czy jest prawidłowy):
        string pattern = horizontal[div];
        if (!pattern.empty()) {
            // tworzymy wzór i uzupełniamy tablicę isFilled (mówiąca o tym, które kratki zapełniliśmy wzorem)
            vector<vector<bool>> isFilled(n, vector<bool>(m, false));
            for (int i = 0; i < div; i++) isFilled[0][i] = true;
            // jesli wzór jest dobry, to dodajemy go do wyniku i wychodzimy z pętli
            if (check(isFilled, pattern)) {
                Res.push_back(div);
                continue;
            }
        }

        // jeśli nie da sie w góre, to pierwszy wzór ustawiamy w dół (sprawdzamy czy się mieści i czy jest prawidłowy):
        pattern = vertical[div];
        if (!pattern.empty()) {
            // tworzymy wzór i uzupełniamy isFilled
            vector<vector<bool>> isFilled(n, vector<bool>(m, false));
            for (int i = 0; i < div; i++) isFilled[i][0] = true;
            // jeśli wzór jest dobry, to dodajemy go do wyniku i wychodzimy z pętli
            if (check(isFilled, pattern))
                Res.push_back(div);
        }
    }

    // wypisywanie wyniku:
    cout << Res.size() << '\n';
    for (auto& res : Res) cout << res << ' ';
}