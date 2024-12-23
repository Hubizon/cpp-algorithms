// Hubert Jastrzębski | Satori 1A (Henryk Portier i Promień Palindromiczny) | 2021-09-19
// https://satori.tcs.uj.edu.pl/contest/7079785/problems/7080104

#include <iostream>
#include <vector>

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

        vector<int> V(n);
        for (auto& v : V) cin >> v;

        vector<vector<bool>> Results;
        for (int b = 0; b <= 1; b++) {
            vector<bool> R(n);
            R[1] = b;
            for (int i = 1; i < n - 1; i++) {
                if (V[i]) R[i + 1] = R[i - 1];
                else R[i + 1] = !R[i - 1];
            }

            vector<int> D(n);
            for (int i = 0, l = 0, r = -1; i < n; i++) {
                int k = (i > r) ? 1 : min(D[l + r - i], r - i + 1);
                while (0 <= i - k && i + k < n && R[i - k] == R[i + k]) k++;
                D[i] = --k;
                if (i + k > r) {
                    l = i - k;
                    r = i + k;
                }
            }

            if (D == V) Results.push_back(R);
        }

        cout << 2 * Results.size() << '\n';
        for (const auto& res : Results) {
            for (const auto r : res) cout << r;
            cout << '\n';
        }
        for (int i = Results.size() - 1; i >= 0; i--) {
            for (const auto r : Results[i]) cout << !r;
            cout << '\n';
        }
    }
}