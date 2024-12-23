// Hubert Jastrzębski | Satori G02 (Anty-portal społecznościowy) | 2021-03-01
// https://satori.tcs.uj.edu.pl/contest/6459992/problems/6733388

#include <iostream>
#include <vector>

using namespace std;

void DFS(const vector<vector<int>>&, vector<bool>&, vector<bool>&);
void explore(const vector<vector<int>>&, vector<bool>&, vector<bool>&, int, bool);

bool is_ok = true;

int main()
{
    int a;
    cin >> a;
    while (a--) {
        is_ok = true;
        int n, m;
        cin >> n >> m;
        vector<vector<int>> G(n);
        for (int i = 0; i < m; i++) {
            int b, c;
            cin >> b >> c;
            G[b - 1].push_back(c - 1);
            G[c - 1].push_back(b - 1);
        }
        vector<bool> visited(n, false); // false - no, true - yes
        vector<bool> group(n, false); // false - A, true - B
        DFS(G, visited, group);
        if (!is_ok)
            cout << "NIE\n";
        else {
            cout << "TAK\n";
            for (const bool& b : group) {
                if (b) cout << "B ";
                else cout << "A ";
            }
            cout << '\n';
        }
    }
}

void DFS(const vector<vector<int>>& G, vector<bool>& visited, vector<bool>& group)
{
    for (int i = 0; i < G.size(); i++) {
        if (!visited[i]) {
            explore(G, visited, group, i, false);
        }
    }
}

void explore(const vector<vector<int>>& G, vector<bool>& visited, vector<bool>& group, int I, bool gr)
{
    if (visited[I]) {
        if (group[I] != gr)
            is_ok = false;
        return;
    }
    visited[I] = true;
    group[I] = gr;
    for (int i = 0; i < G[I].size(); i++)
        explore(G, visited, group, G[I][i], !gr);
}