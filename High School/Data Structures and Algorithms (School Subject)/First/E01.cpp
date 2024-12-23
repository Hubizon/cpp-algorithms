// Hubert Jastrzębski | Satori E01 (Piramida) | 2021-03-01
// https://satori.tcs.uj.edu.pl/contest/6459992/problems/6740450

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int a;
    cin >> a;
    while (a--) {
        unsigned int n, k;
        cin >> n >> k;
        vector<int> traps;
        traps.reserve(n);
        for (int i = n; i--;) {
            char b;
            cin >> b;
            traps.push_back(b - '0');
        }
        unsigned long temp_sum = 1, j = 0;
        for (int i = 0; i < n; i++) {
            if (!traps[i])
                continue;
            j = max(i - 6, 0);
            for (; j < i; j++) {
                temp_sum += traps[j];
            }
            traps[i] = temp_sum % k;
            temp_sum = 0;
        }
        cout << traps[n -1] << '\n';
    }
}