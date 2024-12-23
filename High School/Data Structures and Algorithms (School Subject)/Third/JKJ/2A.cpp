// Hubert Jastrzębski | Satori 2A (Pionki) | 2021-10-09
// https://satori.tcs.uj.edu.pl/contest/7079785/problems/7115785

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
        int n, m;
        cin >> n >> m;

        int sum = 0;
        vector<int> rows(n), columns(m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char c;
                cin >> c;
                if (c == '#') columns[j]++, rows[i]++, sum++;
            }
        }

        auto mr = max_element(rows.begin(), rows.end());
        auto mc = max_element(columns.begin(), columns.end());

        cout << 2 * sum - *mr - *mc << '\n';
    }
}