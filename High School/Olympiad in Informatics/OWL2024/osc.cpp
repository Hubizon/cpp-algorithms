// Hubert Jastrzębski | PREOI / OWL 2024 (Oscypki) | 2024-02-05
// https://sio2.staszic.waw.pl/c/preoi-owl-2024/p/osc/

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <array>
#include <set>

using namespace std;

//constexpr int MAXXY = 1e9 + 10;
constexpr int MAXXY = 2000 + 10;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<array<int, 5>> E; // x, t, y1, y2, i
    // 3 - rozpoczecie, 2 - trawa, 1 - owca, 0 - zakonczenie

    int f;
    cin >> f;
    for (int i = 1; i <= f; i++) {
        int w1, k1, w2, k2;
        cin >> w1 >> k1 >> w2 >> k2;
        w1 += 2, k1 += 2, w2 += 2, k2 += 2;
        E.push_back({ w1, 0, k1, k2, i });
        E.push_back({ w2, 3, k1, k2, i });
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int w, k;
        cin >> w >> k;
        w += 2, k += 2;
        E.push_back({ w, 2, k, k, i });
    }

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int w, k;
        cin >> w >> k;
        w += 2, k += 2;
        E.push_back({ w, 1, k, k, i  });
    }

    sort(E.rbegin(), E.rend());

    vector<int> R(n);
    vector<int> T(MAXXY), F(MAXXY), Rem(MAXXY);
    F.front() = F.back() = -1;
    vector<vector<array<int, 5>>> V(f + 1);
    for (auto& [x, t, y1, y2, i] : E) {
        if (t == 3) { // rozpoczecie ogrodzenia
            Rem[y2] = T[y2 + 1];
            for (int y = y1; y <= y2; y++) {
                T[y] = 0;
                F[y] = i;
            }
        }
        else if (t == 2) { // trawa
            int fence = F[y1];
            for (int y = y1; F[y] == fence; y--)
                T[y]++;
        }
        else if (t == 1) { // owca
            R[i] = T[y1];
        }
        else { // zakonczenie ogrodzenia
            int fence = F[y2 + 1];
            int val = T[y2 + 1];
            for (int y = y1; y <= y2; y++) {
                F[y] = fence;
                T[y] = val;
            }
            for (int y = y1 - 1; F[y] == fence; y--) {
                T[y] += val - Rem[y2];
            }
        }
    }

    for (auto& r : R)
        cout << r << '\n';
}