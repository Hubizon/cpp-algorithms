// Hubert Jastrzębski | PIWO 2019/2020 (Babę zesłał Bóg) | 2020-10-12
// https://szkopul.edu.pl/c/piwo-201920/p/bab/

#include <iostream>

using namespace std;

int main()
{
    const string baba = "baba";

    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        int tempBaba = 0;

        for(int j = 0; j < s.length(); j++)
            if(s[j] == baba[tempBaba])
                tempBaba++;

        if(tempBaba == baba.length())
            cout << "Tak\n";
        else
            cout << "Nie\n";
    }

    return 0;
}