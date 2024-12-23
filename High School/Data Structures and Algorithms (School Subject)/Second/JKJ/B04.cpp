// Hubert Jastrzębski | Satori B04 (Gra w minima) | 2021-05-11
// https://satori.tcs.uj.edu.pl/contest/6941273/problems/6953639

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> V(n);
    for (auto& v : V)
        cin >> v;

    sort(V.begin(), V.end());
    long long temp = 0;
    for (auto v : V)
        temp = max(temp, v - temp);

    cout << temp;
}
