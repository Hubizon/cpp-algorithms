// Hubert Jastrzębski | Satori G05 (Konserwacja) | 2021-04-19
// https://satori.tcs.uj.edu.pl/contest/6459992/problems/6892600

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int DFS(const vector<vector<int>>&, const vector<int>&, const int, vector<int>&);

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
        vector<vector<int>> G(n);
        vector<int> labs(n);
        vector<int> results(n, -1);
        for (auto& l : labs)
            cin >> l;
        for (int i = m, a, b; m--;) {
            cin >> a >> b;
            G[a - 1].push_back(b - 1);
        }

        int max = 0;
        for (int i = n, a; i--;) {
            a = DFS(G, labs, i, results);
            if (a > max)
                max = a;
        }

        int maxColor = 0;
        for (int i = 0; i < n; i++) {
            if (results[i] == max) {
                if (maxColor == 0)
                    maxColor = labs[i];
                else if (labs[i] != maxColor) {
                    max++;
                    break;
                }
            }
        }

        cout << max << '\n';
    }
}

int DFS(const vector<vector<int>>& G, const vector<int>& labs, const int id, vector<int>& results)
{
    if (results[id] != -1)
        return results[id];

    int max = 0, a;
    for (auto& x : G[id]) {
        a = DFS(G, labs, x, results) + (labs[id] != labs[x]);
        if (a > max)
            max = a;
    }

    results[id] = max;
    return max;
}