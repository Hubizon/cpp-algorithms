// Hubert Jastrzębski | PREOI / OWL 2024 (Nonogram) | 2024-02-02
// https://sio2.staszic.waw.pl/c/preoi-owl-2024/p/non/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> X(n), Y(m);
    for (int i = 0; i < n; i++) {
        cin >> X[i].first;
        X[i].second = i;
    }

    for (int i = 0; i < m; i++) {
        cin >> Y[i].first;
        Y[i].second = i;
    }

    vector<vector<bool>> R(n, vector<bool>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            if (c == '-') {
                R[i][j] = true;
                X[i].first++, Y[j].first++;
            }
        }
    }

    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());

    while (X.size()) {
        auto [x, i] = X.back();
        X.pop_back();

        if (x > Y.size()) {
            cout << "NIE";
            exit(0);
        }

        vector<pair<int, int>> TY;
        while (x--) {
            auto [y, j] = Y.back();
            Y.pop_back();
            R[i][j] = !R[i][j];
            if (y > 1)
                TY.push_back({ y - 1, j });
        }

        vector<pair<int, int>> MR(Y.size() + TY.size());
        merge(Y.begin(), Y.end(), TY.rbegin(), TY.rend(), MR.begin());
        Y = MR;
    }

    if (Y.size() && Y.back().first > 0) {
        cout << "NIE";
        exit(0);
    }

    cout << "TAK\n";
    for (auto& r : R) {
        for (auto&& rr : r)
            cout << (rr ? '#' : '.');
        cout << '\n';
    }
}