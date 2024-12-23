// Hubert Jastrzębski | Satori G07 (Banki) | 2021-05-10
// https://satori.tcs.uj.edu.pl/contest/6459992/problems/6950191

#include <iostream>
#include <climits>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

struct Graph
{
  int n, m, s, t;
  vector<tuple<int, int, int>> G;
};

bool bellman_ford(Graph*, vector<int>&);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int z;
    cin >> z;

    while (z--)
    {
        struct Graph* graph = new Graph;
        int n, m;
        cin >> n >> m;
        graph->n = n, graph->m = m;
        vector<int> dist(n, INT_MAX);
        int src, dest, weight;
        while (m--) {
            cin >> src >> dest >> weight;
            graph->G.push_back({ src - 1, dest - 1, weight });
        }
        int s, t;
        cin >> s >> t;
        graph->s = s - 1, graph->t = t - 1;

        if (bellman_ford(graph, dist))
            cout << "Luka w systemie bankowym!";
        else {
            if (dist[graph->t] == INT_MAX)
                cout << "Bank niedostepny!";
            else
                cout << "Minimalny koszt: " << dist[graph->t];
        }
        cout << '\n';
    }
}

bool bellman_ford(Graph* graph, vector<int>& dist)
{
    dist[graph->s] = 0;
    bool isRelaxed = true;
    for (int step = 0; step < graph->n && isRelaxed; step++) {
        isRelaxed = false;
        for (auto& [src, dest, weight] : graph->G) {
            if (dist[src] != INT_MAX && dist[dest] > dist[src] + weight) {
                dist[dest] = dist[src] + weight;
                isRelaxed = true;
            }
        }
    }
    return isRelaxed;
}