// Hubert Jastrzębski | Satori E02 (Mosiężny Most) | 2021-07-23
// https://satori.tcs.uj.edu.pl/contest/6459992/problems/6740466

#include <iostream>
#include <numeric>
#include <vector>
#include <deque>

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
        cin >> n; k = 2;// >> k;
        vector<int> A(n);
        for (auto& a : A) cin >> a;
        int sum = accumulate(A.begin(), A.end(), 0);

        deque <pair<int, int>> dp;
        dp.push_front({ -1, 0 });
        for (int i = 0; i < n; ++i) {
            int value = A[i] + dp.back().second;
            while (!dp.empty() && dp.front().second >= value)
                dp.pop_front();
            dp.push_front({ i, value });
            if (dp.back().first <= i - k - 1)
                dp.pop_back();
        }

        cout << sum - dp.back().second << '\n';
    }
}