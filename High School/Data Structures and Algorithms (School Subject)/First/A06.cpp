// Hubert Jastrzębski | Satori A06 (Palindrom) | 2020-09-21
// https://satori.tcs.uj.edu.pl/contest/6459992/problems/6469297

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int ln;
        cin >> ln;

        string word;
        cin >> word;

        bool isP = true;

        for(int j = 0; j < ln; j++)
            if(word[j] != word[ln - j - 1])
                isP = false;

        if(isP)
            cout << "TAK\n";
        else
            cout << "NIE\n";
    }

    return 0;
}