// Hubert Jastrzębski | Satori G03 (Liczba Bacona) | 2021-03-08
// https://satori.tcs.uj.edu.pl/contest/6459992/problems/6755961

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(const vector<vector<int>>& G, int S, vector<int>& dist);

int main()
{
    int a;
    cin >> a;
    while (a--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> G(n + m);
        for (int i = 0, b, c; i < m; i++) {
            cin >> b;
            while (b--) {
                cin >> c;
                G[c - 1].push_back(i + n);
                G[i + n].push_back(c - 1);
            }
        }
        vector<int> dist(n + m, -2);
        BFS(G, 0, dist);
        for (int i = 0; i < n; i++)
            cout << dist[i] / 2 << ' ';
        cout << '\n';
    }
}

void BFS(const vector<vector<int>>& G, int S, vector<int>& dist)
{
    dist[S] = 0;
    queue<int> Q;
    Q.push(S);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (const int& v : G[u]) {
            if (dist[v] == -2) {
                Q.push(v);
                dist[v] = dist[u] + 1;
            }
        }
    }
}