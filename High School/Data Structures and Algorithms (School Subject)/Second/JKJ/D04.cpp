// Hubert Jastrzębski | Satori D04 (Komisje sejmowe) | 2021-06-21
// https://satori.tcs.uj.edu.pl/contest/6941273/problems/7055999

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
        int n, a;
        cin >> n;
        vector<pair<int, int>> V(n);
        for (int i = n; i--;) {
            cin >> a;
            ++(V[a - 1].first);
        }

        sort(V.rbegin(), V.rend());
        while (n--)
            V[n].second = n + V[n].first;

        const auto max = min_element(V.begin(), V.end(), [](const auto& lhs, const auto& rhs) { return lhs.second < rhs.second; });
        cout << max->second << '\n';
    }
}