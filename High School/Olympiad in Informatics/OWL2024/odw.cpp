// Hubert Jastrzębski | PREOI / OWL 2024 (Odwracanie) | 2024-02-03
// https://sio2.staszic.waw.pl/c/preoi-owl-2024/p/odw/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    string A, B;
    cin >> A >> B;

    vector<int> Pre(n + 1), Suf(n + 1);
    for (int i = 1; i <= n; i++)
        Pre[i] = Pre[i - 1] + (A[i - 1] == B[i - 1]);
    for (int i = n - 1; i >= 0; i--)
        Suf[i] = Suf[i + 1] + (A[i] == B[i]);

    int res = 0;

    // nieparzyste [i; i], [i-1; i; i+1] ...
    for (int i = 0; i < n; i++) {
        string T = A;
        int toRes = 0;
        for (int l = i, r = i; l >= 0 && r < n; l--, r++) {
            swap(T[l], T[r]);
            toRes += (B[l] == T[l]);
            if (l != r)
                toRes += (B[r] == T[r]);
            res = max(res, Pre[l] + toRes + Suf[r + 1]);
        }
    }

    // parzyste [i; i+1], [i-1; i; i+1; i+2]
    for (int i = 0; i < n - 1; i++) {
        string T = A;
        int toRes = 0;
        for (int l = i, r = i + 1; l >= 0 && r < n; l--, r++) {
            swap(T[l], T[r]);
            toRes += (B[l] == T[l]);
            toRes += (B[r] == T[r]);
            res = max(res, Pre[l] + toRes + Suf[r + 1]);
        }
    }

    cout << res;
}