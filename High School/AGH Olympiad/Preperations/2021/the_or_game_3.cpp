// Hubert Jastrzębski | Diamentowy Indeks AGH 2020/2021 III (The OR Game) | 2023-03-20
// https://www.diament.agh.edu.pl/wp-content/uploads/2023/08/informatyka_III_2020_2021.pdf

#include <bits/stdc++.h>

using namespace std;

string decToBin(int x) {
    string S;
    while (x) {
        S += '0' + x % 2;
        x /= 2;
    }
    return string(S.rbegin(), S.rend());
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, g;
    cin >> n >> g;
    const int N = n;

    vector<int> T(n);
    for (auto& t : T)
        cin >> t;

    string G = string(40, '0') + decToBin(g);

    vector<int> T;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        string S = decToBin(x);
        bool is_ok = true;
        for (int j = 0; j < S.size(); j++)
            if (G[G.size() - j - 1] == '0' && S[S.size() - j - 1] == '1')
                is_ok = false;
        if (is_ok)
            T.push_back(x);
    }

    int res = 0;
    for (int bitmask = 0; bitmask < (1 << T.size()); bitmask++) {
        int orall = 0, cnt = 0;
        for (int i = 0; i < n; i++)
            if ((bitmask >> i) & 1)
                orall |= T[i], cnt++;
        if (orall != g)
            res = max(res, cnt);
    }

    cout << N - res;
}
