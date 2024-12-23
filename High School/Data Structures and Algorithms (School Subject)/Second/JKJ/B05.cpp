// Hubert Jastrzębski | Satori B05 (Cysterny) | 2021-05-11
// https://satori.tcs.uj.edu.pl/contest/6941273/problems/6953651

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int z;
    cin >> z;
    while (z--)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> cysterny;
        for (int i = n, b, h, w, d; i--;) {
            cin >> b >> h >> w >> d;
            cysterny.push_back(make_pair(b * 100, w * d));
            cysterny.push_back(make_pair((b + h) * 100, -w * d));
        }
        long long V;
        cin >> V;
        V *= 100;

        sort(cysterny.begin(), cysterny.end());

        long long currentV = 0;
        long long currentH = 0;
        long long lastH = 0;
        long long temp = 0;
        for (auto& cysterna : cysterny) {
            currentH = cysterna.first;
            currentV += (currentH - lastH) * temp;
            lastH = currentH;
            if (currentV >= V) break;
            temp += cysterna.second;
        }

        if (currentV < V)
            cout << "OVERFLOW\n";
        else
            cout << fixed << setprecision(2) << (lastH - (currentV - V) / temp) / 100.00 << '\n';
    }
}