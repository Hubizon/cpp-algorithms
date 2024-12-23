// Hubert Jastrzębski | Satori G08 (Mapa samochodowa) | 2021-11-27
// https://satori.tcs.uj.edu.pl/contest/6459992/problems/6950215

#include <iostream>
#include <unordered_map>
#include <iomanip>
#include <vector>

using namespace std;
constexpr int INF = 1e9;

int main()
{
    int z;
    cin >> z;
    while (z--) {
        int n;
        cin >> n;
        vector<string> IndexToCity(n);
        unordered_map<string, int> CityToIndex(n);
        for (int i = 0; i < n; i++) {
            auto& city = IndexToCity[i];
            cin >> city;
            CityToIndex[city] = i;
        }

        int m;
        cin >> m;
        vector<vector<int>> D(n, vector<int>(n, INF));
        for (int i = 0; i < m; i++) {
            string c1, c2;
            int w;
            cin >> c1 >> c2 >> w;
            auto i1 = CityToIndex[c1], i2 = CityToIndex[c2];
            D[i1][i2] = w;
            D[i2][i1] = w;
        }

        for (int i = 0; i < n; i++) D[i][i] = 0;
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    D[i][j] = min(D[i][j], D[i][k] + D[k][j]);

        cout << setw(12) << " ";
        for (int i = 0; i < n; i++)
            cout << setw(12) << IndexToCity[i];
        cout << "\n";

        for (int i = 0, tempV; i < n; i++) {
            cout << setw(12) << IndexToCity[i];
            for (int j = 0; j < n; j++)
                cout << setw(12) << D[i][j];
            cout << "\n";
        }
    }
}