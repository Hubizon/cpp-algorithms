// Hubert Jastrzębski | Satori 1B (Koło (z) Matematyków) | 2021-09-19
// https://satori.tcs.uj.edu.pl/contest/7079785/problems/7080064

#include <iostream>
#include <algorithm>
#include <numeric>
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
        vector<long long> V(n);
        for (auto& v : V) cin >> v;
        sort(V.begin(), V.end());

        long long sum = accumulate(V.begin(), V.end(), -V.back());
        while (V.size() > 2) {
            if (V.back() < sum) {
                cout << sum + V.back() << '\n';
                break;
            }
            V.pop_back();
            sum -= V.back();
        }
        if (V.size() <= 2) cout << "0\n";
    }
}