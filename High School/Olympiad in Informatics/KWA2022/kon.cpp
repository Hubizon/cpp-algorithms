// Hubert Jastrzębski | Krajowe Warsztaty Algorytmiczne PREOI KWA 2022 (Kontest) | 2022-02-06
// https://sio2.staszic.waw.pl/c/kwa-2022/p/kon/

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <array>
#include <map>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, mm, tt;
    cin >> n >> mm >> tt;

    map<int, vector<pair<ll, ll>>> M; // czas -> zawodnik, punkty
    for (int i = 0; i < mm; i++) {
        int a, s, p;
        cin >> a >> s >> p;
        M[s].push_back({ a, p });
    }

    unordered_map<int, ll> P; // zawodnik -> punkty
    unordered_map<int, int> R; // zawodnik -> czas prowadzenia
    unordered_map<int, int> S; // zawodnik, czas kiedy zaczął prowadzić
    ll maxPoints = 0; // aktualne punkty najlepszego
    for (auto& [s, m] : M) {
        ll newMaxPoints = 0;
        for (auto& [a, p] : m) {
            P[a] += p;
            newMaxPoints = max(newMaxPoints, P[a]);
        }

        if (newMaxPoints == 0 || newMaxPoints < maxPoints) continue;
        if (newMaxPoints > maxPoints) {
            for (auto& [a, t] : S)
                R[a] += s - t;
            S.clear();
        }

        maxPoints = newMaxPoints;
        for (auto& [a, p] : m) {
            if (P[a] == newMaxPoints) {
                if (S[a] == 0) S[a] = s;
                else S[a] = min(S[a], s);
            }
        }
    }

    for (auto& [a, t] : S)
        R[a] += tt - t + 1;

    pair<int, int> res = { INT32_MIN, 0 };
    for (auto& [a, r] : R)
        if (r > res.first || (r == res.first && a < res.second))
            res = { r, a };

    cout << res.second;
}