// Hubert Jastrzębski | Satori D03 (Symetrie) | 2021-06-28
// https://satori.tcs.uj.edu.pl/contest/6941273/problems/7055975

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int z;
    cin >> z;
    while (z--)
    {
        ll n, x, y;
        cin >> n;
        unordered_set<ll> tancerze;
        for (int i = n; i--;) {
            cin >> x >> y;
            tancerze.insert((x << 32) ^ y);
        }

        int isPlus = -1; // -1 or 1
        pair<ll, ll> sum = { 0, 0 };
        pair<ll, ll> temp = { 0, 0 };
        ll q, a, b;
        cin >> q;
        while (q--) {
            char c;
            cin >> c >> a >> b;
            if (c == 'Q') {
                temp = { sum.first - a, sum.second - b };
                temp = { temp.first * isPlus, temp.second * isPlus };
                if (tancerze.count((temp.first << 32) ^ temp.second)) cout << "TAK\n";
                else cout << "NIE\n";
            }
            else {
                sum = { sum.first * -1, sum.second * -1 };
                sum.first += 2 * a;
                sum.second += 2 * b;
                isPlus *= -1;
            }
        }
    }
}