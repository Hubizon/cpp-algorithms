// Hubert Jastrzębski | Satori B01 (Dodawanie) | 2020-10-26
// https://satori.tcs.uj.edu.pl/contest/6459992/problems/6539683

#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a, b, result;
    cin >> a >> b;

    if (b.size() > a.size())
        swap(a, b);

    bool doAdd = false;
    for (int i = b.size(); i != 0; i--)
    {
        short temp = a.back() + b.back() + doAdd - 2 * '0';
        if (temp >= 10) {
            result.push_back(temp - 10 + '0');
            doAdd = true;
        }
        else {
            result.push_back(temp + '0');
            doAdd = false;
        }
        a.pop_back();
        b.pop_back();
    }

    int howMuchLonger = a.size() - b.size();
    while (howMuchLonger + doAdd > 1)
    {
        short temp = a[howMuchLonger - 1] - '0' + doAdd;
        if (temp >= 10) {
            result.push_back(temp - 10 + '0');
        }
        else {
            result.push_back(temp + '0');
            doAdd = false;
        }
        howMuchLonger--;
    }
    if (doAdd)
        result.push_back('1');
    else if (a.size() != b.size())
        result.push_back(a[0]);

    reverse(result.begin(), result.end());
    cout << result;
}