// Hubert Jastrzębski | Satori B13 (Sumy) | 2021-02-22
// https://satori.tcs.uj.edu.pl/contest/6459992/problems/6733602

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int a;
    cin >> a;
    while (a--)
    {
        int n, K;
        cin >> n >> K;
        vector<int> V;
        V.reserve(n);
        for (int i = n; i--;) {
            int b;
            cin >> b;
            V.push_back(b);
        }
        int i = 0, j = 0;
        int sum = 0, result = 0;
        while (i < n) {
            while (j < n && sum < K)
                sum += V[j++];
            if (sum == K)
                result++;
            sum = sum - V[i++];
        }
        cout << result << '\n';
    }
}