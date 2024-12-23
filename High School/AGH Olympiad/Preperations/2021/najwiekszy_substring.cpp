// Hubert Jastrzębski | Diamentowy Indeks AGH 2020/2021 III (Największy substring) | 2023-03-03
// https://www.diament.agh.edu.pl/wp-content/uploads/2023/08/informatyka_III_2020_2021.pdf

#include <iostream>

using namespace std;

int main()
{
    string S;
    cin >> S;

    auto max_char = [&]() -> int {
        pair<int, int> res = { -1, -1 };
        for (int i = 0; i < S.size(); i++) {
            if (S[i] > res.first) {
                res = { S[i], i };
            }
        }
        return res.second;
    };

    string res;
    int c = max_char();
    while (S.size()) {
        res += S[c];
        S = S.substr(c + 1);
        c = max_char();
    }

    cout << res;
}
