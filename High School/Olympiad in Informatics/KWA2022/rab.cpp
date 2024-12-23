// Hubert Jastrzębski | Krajowe Warsztaty Algorytmiczne PREOI KWA 2022 (Rabunki) | 2022-02-10
// https://sio2.staszic.waw.pl/c/kwa-2022/p/rab/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> A(n), B(n);
    for (auto& a : A) cin >> a;
    for (auto& b : B) cin >> b;

    long long res = 0;
    for (int i = 0; i < n; i++)
        res += abs(A[i] - B[i]);
    cout << res << '\n';

    stack<int> S;
    if (A.front() > B.front()) cout << "1 ";
    else S.push(0);

    for (int i = 1; i < n; i++) {
        if (A[i] > B[i]) {
            while (S.size() && B[S.top()] - A[S.top()] < A[i] - B[i]) {
                cout << S.top() + 1 << ' ';
                S.pop();
            }
            S.push(i);
        }
        else {
            S.push(i);
        }
    }

    while (S.size()) {
        cout << S.top() + 1 << ' ';
        S.pop();
    }
}