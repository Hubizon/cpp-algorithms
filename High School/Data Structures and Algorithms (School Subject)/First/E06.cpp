// Hubert Jastrzębski | Satori E06 (placeholder) | 2021-03-22
// https://satori.tcs.uj.edu.pl/contest/6459992/problems/6810014

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int a;
    cin >> a;
    while (a--)
    {
        int n, B;
        cin >> n >> B;
        vector<int> S;
        S.reserve(n);
        vector<int> V;
        V.reserve(n);
        int t1, t2;
        for (int i = n; i--;) {
            cin >> t1 >> t2;
            S.push_back(t1);
            V.push_back(t2);
        }

        vector<int> to_fill(B + 1, 0);
        vector<vector<int>> K(n + 1, to_fill);
        for (int i = 1; i <= n; i++)
        {
            for (int b = 1; b <= B; b++)
            {
                if (b - S[i - 1] < 0)
                    K[i][b] = K[i - 1][b];
                else
                    K[i][b] = max(K[i - 1][b], V[i - 1] + K[i - 1][b - S[i - 1]]);
            }
        }

        cout << K[n][B] << '\n';
    }
}