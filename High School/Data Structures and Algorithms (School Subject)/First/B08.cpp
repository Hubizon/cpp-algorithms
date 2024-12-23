// Hubert Jastrzębski | Satori B08 (Ciąg rekurencyjny) | 2020-11-27
// https://satori.tcs.uj.edu.pl/contest/6459992/problems/6595072

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

void fillP(vector<vector<long long>>& P, int k)
{
    for (int i = 0; i < k - 1; i++)
    {
        vector<long long> toP;
        for (int j = k; j--;)
            toP.push_back(0);
        toP[i] = 1;
        P.push_back(toP);
    }
}

vector<vector<long long>> mul(const vector<vector<long long>> A, const vector<vector<long long>> B, int k)
{
    vector <vector<long long>> R;
    for (int i = 0; i < k; i++)
    {
        vector<long long> toR;
        for (int j = k; j--;)
            toR.push_back(0);
        R.push_back(toR);
    }

    for (int i = 0; i < k; i++)
        for (int z = 0; z < k; z++)
            for (int j = 0; j < k; j++) {
                R[i][j] += A[i][z] * B[z][j];
                R[i][j] %= 1000;
            }
    return R;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (; n--;)
    {
        int k, m;
        cin >> k >> m;
        m -= 2;
        vector<long long> A;
        vector <vector<long long>> P;
        vector<long long> toP;
        P.push_back(toP);
        for (int i = k; i--;) {
            int c;
            cin >> c;
            P[0].push_back(c);
        }
        for (int i = k; i--;) {
            int a;
            cin >> a;
            A.push_back(a);
        }
        fillP(P, k);
        vector<vector<long long>> temp = P;
        while (m > 0)
        {
            if (m % 2 == 1)
                P = mul(P, temp, k);
            temp = mul(temp, temp, k);
            m /= 2;
        }
        long long result = 0;
        if (k == 1)
            cout << setfill('0') << setw(3) << ((P[0][0] * A[0]) % 1000) << "\n";
        else
        {
            if (m < 0)
                cout << setfill('0') << setw(3) << (A[1] % 1000) << "\n";
            else
            {
                for (int i = 0; i < k; i++) {
                    result += P[k - 1][i] * A[i];
                    result %= 1000;
                }
                result %= 1000;
                cout << setfill('0') << setw(3) << result << "\n";
            }
        }
    }
}