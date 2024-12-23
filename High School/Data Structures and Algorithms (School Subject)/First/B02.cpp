// Hubert Jastrzębski | Satori B02 (Odejmowanie) | 2020-11-00
// https://satori.tcs.uj.edu.pl/contest/6459992/problems/6539723

#include <bits/stdc++.h>

using namespace std;

bool isSmaller(string a, string b)
{
    int aSize = a.length();
    int bSize = b.length();

    if (aSize < bSize)
        return true;
    if (bSize < aSize)
        return false;

    for (int i = 0; i < aSize; i++)
        if (a[i] < b[i])
            return true;
        else if (a[i] > b[i])
            return false;

    return false;
}

int main()
{
    string a, b, result = "";
    cin >> a >> b;

    if (isSmaller(a, b))
        swap(a, b);

    /*if (b.size() > a.size())
        swap(a, b);
    else if (a.size() == b.size())
        if (a.compare(b) == -1)
            swap(a, b);*/

    bool doSubstract = false;
    for (int i = b.size(); i != 0; i--)
    {
        int temp = (a.back() - b.back()) - doSubstract;
        if (temp < 0) {
            result.push_back(temp + 10 + '0');
            doSubstract = true;
        }
        else {
            result.push_back(temp + '0');
            doSubstract = false;
        }
        a.pop_back();
        b.pop_back();
    }

    int howMuchLonger = a.size() - b.size();
    while (howMuchLonger + doSubstract > 1)
    {
        long temp = a[howMuchLonger - 1] - '0' - doSubstract;
        if (temp < 0) {
            result.push_back(temp + 10 + '0');
        }
        else {
            result.push_back(temp + '0');
            doSubstract = false;
        }
        howMuchLonger--;
    }
    if (howMuchLonger)
        result.push_back(a[0]);
    else
    {
        for (int i = result.size() - 1; i > 0; i--)
        {
            if (result[i] == '0')
                result.pop_back();
            else
                break;
        }
    }

    reverse(result.begin(), result.end());
    cout << result;
}