// Hubert Jastrzębski | Satori E01 (Gazeta) | 2021-07-05
// https://satori.tcs.uj.edu.pl/contest/6941273/problems/7059914

#include <iostream>
#include <algorithm>
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
        int n, k;
        cin >> n >> k;
        vector<int> result;
        if (k % 2 == 0) result = { k - 1, n - k + 1, n - k + 2 };
        else result = { k + 1, n - k, n - k + 1 };
        sort(result.begin(), result.end());
        for (auto& r : result) cout << r << ' ';
        cout << '\n';
    }
}