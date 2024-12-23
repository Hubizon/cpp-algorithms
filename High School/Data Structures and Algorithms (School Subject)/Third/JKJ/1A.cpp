// Hubert Jastrzębski | Satori 1A (Pudełka) | 2021-09-19
// https://satori.tcs.uj.edu.pl/contest/7079785/problems/7080052

#include <iostream>
#include <algorithm>
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
        vector<pair<int, int>> V(6);
        for (auto& [a, b] : V) {
            cin >> a >> b;
            if (a > b) swap(a, b);
        }

        sort(V.begin(), V.end());
        if (V[0] == V[1] && V[2] == V[3] && V[4] == V[5]
            && V[1].first == V[2].first && V[3].second == V[4].second && V[5].first == V[0].second)
            cout << "MOZLIWE\n";
        else cout << "NIEMOZLIWE\n";
    }
}