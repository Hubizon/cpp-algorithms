// Hubert Jastrzębski | Satori A13 (Słowo w słowo) | 2020-10-12
// https://satori.tcs.uj.edu.pl/contest/6459992/problems/6497123

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        string s, ss;
        cin >> s >> ss;

        int tempS = 0;
        for(int j = 0; j < ss.length(); j++)
            if(s[tempS] == ss[j])
                tempS++;

        if(tempS == s.length())
            cout << "TAK" << endl;
        else
            cout << "NIE" << endl;
    }

    return 0;
}