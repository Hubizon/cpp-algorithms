// Hubert Jastrzębski | Diamentowy Indeks AGH 2018/2019 I (Zadanie 3) | 2023-03-06
// https://www.diament.agh.edu.pl/wp-content/uploads/2023/08/matematyka_i_2018_2019.pdf

#include <iostream>
#include <functional>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

string hpow(string S) {
    int dec = S.find('.');
    S = S.substr(0, dec) + S.substr(dec + 1);
    dec = S.size() - dec;

    int n = S.size();
    vector<int> V(n + n);
    for (int i = n - 1; i >= 0; i--) {
        int c1 = S[i] - '0';
        for (int j = n - 1; j >= 0; j--) {
            int c2 = S[j] - '0';
            V[i + j + 1] += c1 * c2;
        }
    }

    for (int i = V.size() - 1; i > 0; i--) {
        if (V[i] >= 10) {
            V[i - 1] += V[i] / 10;
            V[i] %= 10;
        }
    }

    string res = "";
    for (int i = 0; i < V.size(); i++)
        res.push_back(V[i] + '0');

    int newdec = res.size() - 2 * dec;
    res = res.substr(0, newdec) + '.' + res.substr(newdec);

    return res;
}

void solve() {
    int m, n;
    cin >> m >> n;

    int xsqrt = sqrt(m), res = 0;
    string xs = to_string(xsqrt) + ".";
    for (int i = 0; i < n; i++) {
        char j;
        for (j = '1'; j <= '9'; j++) {
            string t = hpow(xs + j);
            int x = stoi(t.substr(0, t.find('.')));
            if (x >= m)
                break;
        }

        res += (--j - '0');
        xs += j;
    }

    cout << res;
}


int main()
{
    solve();
}