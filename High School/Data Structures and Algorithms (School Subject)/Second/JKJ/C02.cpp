// Hubert Jastrzębski | Satori C02 (Orgotrafia) | 2021-06-12
// https://satori.tcs.uj.edu.pl/contest/6941273/problems/7039484

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

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
        string s1, s2;
        cin >> s1 >> s2;
        vector<char> V(26);
        for (char c : s1) V[c - 'a']++;
        for (char c : s2) V[c - 'a']--;
        cout << "PN"[V != vector<char>(26) || s1.front() != s2.front() || s1.back() != s2.back()] << '\n';
    }
}