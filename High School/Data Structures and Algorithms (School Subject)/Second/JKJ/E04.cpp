// Hubert Jastrzębski | Satori E04 (Szał zakupów) | 2021-07-06
// https://satori.tcs.uj.edu.pl/contest/6941273/problems/7059958

#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

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
        vector < pair<long long, pair<long long, long long>>> V;
        long long everything = 0;
        for (int i = 0; i < n; ++i) {
            long long a, b, p, o;
            cin >> a >> b >> p >> o; --a;
            V.push_back({ a, { o, -a * o } });
            V.push_back({ b, { -o, a * o } });
            everything += p;
        }
        sort(V.begin(), V.end());

        pair<long long, long long> result = { LLONG_MIN, LLONG_MIN };
        long long a = 0, b = 0;
        for (auto& [day, v] : V) {
            long long prom = a * day + b;
            if (prom > result.second) result = { day, prom };
            a += v.first;
            b += v.second;
        }

        cout << result.first << ' ' << everything - result.second << '\n';
    }
}