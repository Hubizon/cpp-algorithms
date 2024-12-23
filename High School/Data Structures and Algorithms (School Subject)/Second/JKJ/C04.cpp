// Hubert Jastrzębski | Satori C04 (Naleśniki) | 	2021-06-12
// https://satori.tcs.uj.edu.pl/contest/6941273/problems/7039520

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> V(n), positions(n), result;
    result.reserve(n * 6);
    for (int i = 0, a; i < n; i++) {
        cin >> a;
        V[i] = --a;
        positions[a] = i;
    }

    int p = 0;
    for (int i = 0; i < n; i++) {
        p = positions[i];
        if (i != p) {
            if (p == i + 1) result.insert(result.end(), { p + 1, 2, p + 1 });
            else result.insert(result.end(), { i + 1, p + 1, p, p - 1, p, i + 1 });
            iter_swap(V.begin() + i, V.begin() + p);
            iter_swap(positions.begin() + V[i], positions.begin() + V[p]);
        }
    }

    cout << result.size() << '\n';
    for (int r : result)
        cout << r << '\n';
}