// Hubert Jastrzębski | Satori G11 (Linie autobusowe) | 2021-11-22
// https://satori.tcs.uj.edu.pl/contest/7079339/problems/7263020

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int z;
    cin >> z;
    while (z--) {
        int n, m;
        cin >> n >> m;
        vector<vector<pair<int, int>>> G(n + 1);
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            G[a].push_back({ b, i });
            G[b].push_back({ a, i });
        }

        for (int i = 1; i <= n; i++) {
            if (G[i].size() % 2 != 0) {
                G[0].push_back({ i, m });
                G[i].push_back({ 0, m++ });
            }
        }

        if (G[0].size() == 0) {
            G[0].push_back({ 1, m++ });
            G[1].push_back({ 0, m++ });
        }

        vector<bool> vis(m);
        vector<int> Res;
        stack<int> S;
        S.push(0);
        while (!S.empty()) {
            auto v = S.top();
            if (G[v].empty()) {
                S.pop();
                Res.push_back(v);
                continue;
            }
            auto [w, i] = G[v].back();
            G[v].pop_back();
            if (!vis[i]) {
                vis[i] = true;
                S.push(w);
            }
        }

        int l = count(Res.begin(), Res.end(), 0) - 1;
        cout << l << '\n';
        auto prev = Res.begin() + 1;
        for (int i = 0; i < l; i++) {
            auto next = find(prev, Res.end(), 0);
            int k = next - prev;
            cout << k << ' ';
            for (auto v = prev; v != next; v++)
                cout << *v << ' ';
            prev = next + 1;
            cout << '\n';
        }
    }
}