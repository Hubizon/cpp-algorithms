// Hubert Jastrzębski | Satori D02 (Trójkąty) | 2021-06-21
// https://satori.tcs.uj.edu.pl/contest/6941273/problems/7055955

#include <iostream>
#include <algorithm>
#include <string>
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
        int n, i = 2;
        cin >> n;
        vector<int> V(n);
        for (auto& v : V) cin >> v;

        sort(V.begin(), V.end());
        while (i < n && V[i - 1] + V[i - 2] <= V[i]) i++;

        if (i < n) cout << V[i - 2] << V[i - 1] << V[i];
        else cout << "NIE\n";
    }
}