// Hubert Jastrzębski | Satori C05 (Słupki) | 2021-01-26
// https://satori.tcs.uj.edu.pl/contest/6459992/problems/6701345

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    int a;
    cin >> a;
    for (; a--;)
    {
        int n;
        cin >> n;
        vector<long long> height(n + 2);
        height[0] = -1;
        height[n + 1] = -1;
        vector<long long> left(n + 2);
        vector<long long> right(n + 2);
        stack<long long> S;

        for (long i = 1; i <= n; i++) {
            long long h;
            cin >> h;
            height[i] = h;
        }

        S.push(0);
        for (long i = 1; i <= n; i++)
        {
            long long h = height[i];
            while (height[S.top()] >= h)
                S.pop();
            left[i] = S.top();
            S.push(i);
        }

        while (!S.empty())
            S.pop();
        S.push(n + 1);
        for (long i = n; i > 0; i--)
        {
            long long h = height[i];
            while (height[S.top()] >= h)
                S.pop();
            right[i] = S.top();
            S.push(i);
        }

        long long max = 0;
        for (int i = 1; i <= n; i++)
        {
            long long area = (long long)(height[i] * (right[i] - left[i] - 1));
            if (area > max)
                max = area;
        }
        cout << max << "\n";
    }
}