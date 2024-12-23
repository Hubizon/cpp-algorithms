// Hubert Jastrzębski | Satori H01 (Elfy i orkowie) | 2022-10-14
// https://satori.tcs.uj.edu.pl/contest/7808974/problems/7956494

#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int z;
    cin >> z;
    while (z--) {
        int n;
        cin >> n;

        deque<int> O(n), E(n);
        for (auto& o : O) cin >> o;
        for (auto& e : E) cin >> e;

        sort(O.begin(), O.end());
        sort(E.begin(), E.end());

        int res = 0;
        while (O.size()) {
            if (O.front() < E.front() || O.back() < E.back()) {
                O.pop_front(), E.pop_back();
                res--;
            }
            else if (O.front() > E.front()) {
                O.pop_front(), E.pop_front();
                res++;
            }
            else if (O.back() > E.back()) {
                O.pop_back(), E.pop_back();
                res++;
            }
            else {
                if (E.front() == E.back()) break;
                O.pop_front(), E.pop_back();
                res--;
            }
        }

        cout << 200 * res << '\n';
    }
}