// Hubert Jastrzębski | XXIX OI II (Bomberman) | 2022-02-17
// https://sio2.mimuw.edu.pl/c/oi29-2/p/bom/

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>

using namespace std;

vector<vector<int>> createGraph(vector<string>& V) {
    int n = V.size();
    vector<vector<int>> G(n * n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            auto& c = V[i][j];
            if (c != '#' && c != 'X') {
                if (i != n - 1) {
                    if (V[i + 1][j] != '#' && V[i + 1][j] != 'X') {
                        G[i * n + j].push_back((i + 1) * n + j);
                        G[(i + 1) * n + j].push_back(i * n + j);
                    }
                }
                if (j != n - 1) {
                    if (V[i][j + 1] != '#' && V[i][j + 1] != 'X') {
                        G[i * n + j].push_back(i * n + j + 1);
                        G[i * n + j + 1].push_back(i * n + j);
                    }
                }
            }
        }
    }
    return G;
}

pair<int, vector<int>> minDist(vector<vector<int>>& G, int src, int dest, int n) {
    vector<int> dist(G.size(), INT32_MAX);
    vector<int> prev(G.size(), -1);
    dist[src] = 0; prev[src] = src;
    queue<int> Q; Q.push(src);
    while (!Q.empty()) { // bfs z serweru na Discordzie
        auto u = Q.front(); Q.pop();
        for (auto& v : G[u]) {
            if (dist[v] == INT32_MAX) {
                dist[v] = dist[u] + 1;
                prev[v] = u;
                Q.push(v);
            }
        }
    }

    return { dist[dest], prev };
}

stack<char> getPath(vector<int>& prev, int src, int dest, int n) {
    stack<char> R;
    int p = dest;
    while (p != src) {
        int pr = prev[p];
        if (pr == p + 1) R.push('L');
        if (pr == p - 1) R.push('P');
        if (pr == p + n) R.push('G');
        if (pr == p - n) R.push('D');
        p = pr;
    }
    return R;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<string> V(n, string(n, '.'));
    bool isFirstSubtask = true;
    pair<int, int> begin, end;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            auto& c = V[i][j];
            cin >> c;
            if (c == '#')
                isFirstSubtask = false;
            if (c == 'P')
                begin = { i, j };
            if (c == 'K')
                end = { i, j };
        }
    }

    int src = begin.first * n + begin.second;
    int dest = end.first * n + end.second;

    if (isFirstSubtask) {
        // część kodu i pomysłu z https://www.geeksforgeeks.org/shortest-distance-two-cells-matrix-grid/
        vector<vector<int>> G = createGraph(V);
        auto [x, prev] = minDist(G, src, dest, n);

        if (x == INT32_MAX) {
            cout << "NIE";
            return 0;
        }

        cout << x << '\n';
        cout << begin.first + 1 << ' ' << begin.second + 1 << '\n';

        stack<char> R = getPath(prev, src, dest, n);
        while (R.size()) {
            cout << R.top(); R.pop();
        }

    }

    else {
        int res = INT32_MAX;
        vector<int> path;
        pair<int, int> bomb;

        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                if (V[x][y] == 'X') continue;
                vector<string> V2 = V;
                for (int i = x; i < n; i++) { // w dół
                    if (V2[i][y] == 'X') break;
                    V2[i][y] = '.';
                }
                for (int i = x; i >= 0; i--) { // w górę
                    if (V2[i][y] == 'X') break;
                    V2[i][y] = '.';
                }
                for (int j = y; j < n; j++) { // w prawo
                    if (V2[x][j] == 'X') break;
                    V2[x][j] = '.';
                }
                for (int j = y; j >= 0; j--) { // w lewo
                    if (V2[x][j] == 'X') break;
                    V2[x][j] = '.';
                }

                vector<vector<int>> G = createGraph(V2);
                auto [dist, prev] = minDist(G, src, dest, n);
                if (dist < res) {
                    res = dist;
                    path = prev;
                    bomb = { x + 1, y + 1 };
                }
            }
        }

        if (res == INT32_MAX)
            cout << "NIE";
        else {
            cout << res << '\n';
            cout << bomb.first << ' ' << bomb.second << '\n';
            stack<char> R = getPath(path, src, dest, n);
            while (R.size()) {
                cout << R.top(); R.pop();
            }
        }
    }

    /*else { // n^3    edit: jednak to nie zadziała :(

        int levels = 2 * n;

        vector<vector<pair<int, int>>> GG(n * n);  // vertex, level
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                auto& c = V[i][j];
                if (c != 'X') {
                    if (i != n - 1) { // w dół
                        if (V[i + 1][j] != 'X') {
                            if (V[i + 1][j] != '#')
                                GG[i * n + j].push_back({ (i + 1) * n + j, false });
                            else
                                GG[i * n + j].push_back({ (i + 1) * n + j, true });
                        }
                    }
                    if (i != 0) { // w górę
                        if (V[i - 1][j] != 'X') {
                            if (V[i - 1][j] != '#')
                                GG[i * n + j].push_back({ (i - 1) * n + j, false });
                            else
                                GG[i * n + j].push_back({ (i - 1) * n + j, true });
                        }
                    }
                    if (j != n - 1) { // w prawo
                        if (V[i][j + 1] != 'X') {
                            if (V[i][j + 1] != '#')
                                GG[i * n + j].push_back({ i * n + j + 1, false });
                            else
                                GG[i * n + j].push_back({ i * n + j + 1, true });
                        }
                    }
                    if (j != 0) { // w lewo
                        if (V[i][j - 1] != 'X') {
                            if (V[i][j - 1] != '#')
                                GG[i * n + j].push_back({ i * n + j - 1, false });
                            else
                                GG[i * n + j].push_back({ i * n + j - 1, true });
                        }
                    }
                }
            }
        }

        vector<vector<vector<pair<int, int>>>> G(levels, GG);
        vector<vector<int>> dist(levels, vector<int>(G[0].size(), INT32_MAX));
        vector<vector<int>> prev(levels, vector<int>(G[0].size(), -1));
        dist[0][src] = 0; prev[0][src] = src;
        queue<pair<int, int>> Q; Q.push({ src, 0 });
        while (!Q.empty()) { // bfs z serweru na Discordzie
            auto [u, lvl] = Q.front(); Q.pop();
            for (auto& [v, up] : G[lvl][u]) {
                if (lvl + up >= levels) continue;
                if (dist[lvl + up][v] == INT32_MAX) {
                    dist[lvl + up][v] = dist[lvl + up][u] + 1;
                    prev[lvl + up][v] = u;
                    Q.push({ v, lvl + up });
                }
            }
        }

        cout << ""; // oj :c
    }*/
}