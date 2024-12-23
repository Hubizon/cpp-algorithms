// Hubert Jastrzębski | Satori B02 (Odejmowanie) | 2024-02-02
// https://satori.tcs.uj.edu.pl/contest/6459992/problems/6539723

#include <iostream>
#include <string>

using namespace std;

int main() {
    string a, b, res;
    cin >> a >> b;

    if (a.size() < b.size() || (a.size() == b.size() && a < b))
        swap(a, b);

    b = string(a.size() - b.size(), '0') + b;

    for (int i = a.size() - 1; i >= 0; i--) {
        int x = a[i] - b[i];
        if (x < 0) {
            x += 10;
            a[i - 1]--;
        }
        res += x + '0';
    }

    while (res.size() > 1 && res.back() == '0')
        res.pop_back();

    cout << string(res.rbegin(), res.rend());
}