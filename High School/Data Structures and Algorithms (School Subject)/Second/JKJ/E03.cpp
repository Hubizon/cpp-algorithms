// Hubert Jastrzębski | Satori E03 (Słoiki) | 2021-07-05
// https://satori.tcs.uj.edu.pl/contest/6941273/problems/7059942

#include <iostream>
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
        vector<int> A(n);
        vector<int> B(n);
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            A[i] = a - 1;
            B[a - 1] = i;
        }

        int result = 0;
        for (int i = 0; i < n; ++i) {
            if (B[i] == i) continue;
            ++result;
            B[A[i]] = B[i];
            A[B[i]] = A[i];
            A[i] = i;
            B[i] = i;
        }

        cout << result << '\n';
    }
}