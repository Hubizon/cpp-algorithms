// Hubert Jastrzębski | Satori C02 (Obrazy i pokoje) | 2021-01-18
// https://satori.tcs.uj.edu.pl/contest/6459992/problems/6626935

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
        int n, out = 0;
        cin >> n;
        vector<int> paintings(n);
        vector<int> deq(n);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            paintings[i] = x;
            deq[x - 1]++;
        }
        stack<int> S;
        for (int i = 0; i < n; i++) {
            if (!deq[i])
                S.push(i);
        }
        while (!S.empty())
        {
            int v = S.top();
            S.pop();
            int& temp = deq[paintings[v] - 1];
            if (temp == 1)
                S.push(paintings[v] - 1);
            else
                temp--;
            out++;
        }
        cout << n - out << endl;
    }
}