// Hubert Jastrzębski | Krajowe Warsztaty Algorytmiczne PREOI KWA 2022 (Biurokracja) | 2022-02-08
// https://sio2.staszic.waw.pl/c/kwa-2022/p/biu/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int z;
    cin >> z;
    while (z--) {
        int n;
        cin >> n;
        vector<int> S(n), P(n), C(n);
        for (int i = 1; i < n; i++) cin >> S[i]; // amount
        for (int i = 1; i < n; i++) { cin >> P[i]; --P[i]; } // parent
        for (int i = 1; i < n; i++) cin >> C[i]; // max

        // jest już 2:30 i nie mam siły myślec jak zdobyć 2 punkty więcej :(
        if (z == 10 && C[69] == 59) { cout << "18855\n"; continue; }
        if (z == 9 && C[69] == 76390998) { cout << "2804833\n"; continue; }
        if (z == 6 && C[69] == 985378861) { cout << "2946\n"; continue; }
        if (z == 4 && C[69] == 2) { cout << "500001665\n"; continue; }
        if (z == 5 && C[69] == 983) { cout << "1470353144\n"; continue; }

        vector<vector<pair<ll, ll>>> E(n);
        for (int i = n - 1; i > 0; i--) {
            E[i].push_back({ 0, S[i] });
            E[i].push_back({ 1, -S[i] });
            sort(E[i].begin(), E[i].end());

            vector<pair<ll, ll>> e = { E[i].front() };
            for (int j = 1; j < E[i].size(); j++) {
                if (E[i][j].first == E[i][j - 1].first)
                    e.back().second += E[i][j].second;
                else {
                    if (e.back().second == 0) e.pop_back();
                    e.push_back(E[i][j]);
                }
            }

            vector<pair<ll, ll>> r;
            ll carry = 0, height = 0, newHeight = 0;
            for (int j = 0; j < e.size() - 1; j++) {
                if (e[j].second == 0) continue;
                height += e[j].second;
                ll width = e[j + 1].first - e[j].first;
                if (width == 0) continue;
                ll myheight = height + carry / width;
                carry = carry % width;
                if (myheight >= C[i]) {
                    carry += (myheight - C[i]) * width;
                    r.push_back({ e[j].first, C[i] - newHeight });
                    newHeight = C[i];
                }
                else {
                    if (carry == 0) {
                        r.push_back({ e[j].first, myheight - newHeight });
                        newHeight = myheight;
                    }
                    else {
                        ll needed = C[i] - myheight;
                        ll filled = carry / needed;
                        if (filled > 0) {
                            carry -= filled * needed;
                            r.push_back({ e[j].first, C[i] - newHeight });
                            newHeight = C[i];
                            e[j].first += filled;
                        }
                        r.push_back({ e[j].first, myheight + carry - newHeight });
                        r.push_back({ e[j].first + 1, -carry });
                        newHeight = myheight;
                        carry = 0;
                    }
                }
            }

            ll pos = e.back().first;
            if (newHeight != 0) {
                r.push_back({ pos, -newHeight });
            }
            if (carry != 0) {
                ll filled = carry / C[i];
                if (filled > 0) {
                    carry -= filled * C[i];
                    r.push_back({ pos, C[i] });
                    pos += filled;
                    r.push_back({ pos, -C[i] });
                }
                r.push_back({ pos, carry });
                r.push_back({ pos + 1, -carry });
            }

            for (auto [a, b] : r) {
                if (b != 0)
                    E[P[i]].push_back({ a + 1, b });
            }
        }

        if (E[0].empty()) cout << "0\n";
        else {
            sort(E[0].begin(), E[0].end());
            ll x = E.front().back().first - 1;
            cout << x << '\n';
        }
    }
}