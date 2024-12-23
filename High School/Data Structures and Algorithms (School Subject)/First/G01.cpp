// Hubert Jastrzębski | Satori G01 (facepalm.bt) | 2021-02-22
// https://satori.tcs.uj.edu.pl/contest/6459992/problems/6733376

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(const vector<vector<int>> &G, int S, vector<int> &dist);

int main()
{
    int a;
    cin >> a;
    while (a--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> G(n);
        for (int i = 0; i < m; i++) {
            int b, c;
            cin >> b >> c;
            G[b - 1].push_back(c - 1);
            G[c - 1].push_back(b - 1);
        }
        int no, result = 1;
        cin >> no;
        cout << "Znajomi numeru " << no-- << ":\n";
        vector<int> dist(n, INT32_MAX);
        BFS(G, no, dist);
        for (int i = 0; i < n; i++) {
            if (dist[i] != INT32_MAX && dist[i] != 0)
                cout << i + 1 << ": " << dist[i] << '\n';
        }
        for (int i = 0; i < n; i++) {
            if (dist[i] == INT32_MAX) {
                BFS(G, i, dist);
                result++;
            }
        }
        cout << "Grup znajomych jest " << result << ".\n";
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
            if (dist[v] == INT32_MAX) {
                Q.push(v);
                dist[v] = dist[u] + 1;
            }
        }
    }
}