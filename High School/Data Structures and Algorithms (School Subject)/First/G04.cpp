// Hubert Jastrzębski | Satori G04 (Komisja śledcza) | 2021-03-23
// https://satori.tcs.uj.edu.pl/contest/6459992/problems/6809875

#include <iostream>
#include <vector>

using namespace std;

void DFS(const vector<vector<int>>&, vector<char>&, int, vector<int>&);
bool is_cycle;

int main()
{
    int a;
    cin >> a;
    while (a--)
    {
        int n, m;
        cin >> n >> m;

        //ALGORYTM 2:
        vector<vector<int>> G(n);
        vector<char> colors(n);
        vector<int> R;
        int t1, t2;
        for (int i = m; i--;) {
            cin >> t1 >> t2;
            G[t2 - 1].push_back(t1 - 1);
        }

        is_cycle = false;
        for (int i = 0; i < n; i++)
            DFS(G, colors, i, R);


        if (!is_cycle) {
            cout << "OK\n";
            for (int& r : R)
                cout << (r + 1) << ' ';
            cout << '\n';
        }
        else
            cout << "CYKL\n";

    }
}

void DFS(const vector<vector<int>>& G, vector<char>& colors, int id, vector<int>& R)
{
    if (colors[id] == 's') {
        is_cycle = true;
        return;
    }
    if (colors[id] == 'c')
        return;
    colors[id] = 's';

    for (int i = 0; i < G[id].size(); i++)
        DFS(G, colors, G[id][i], R);

    colors[id] = 'c';
    R.push_back(id);
}