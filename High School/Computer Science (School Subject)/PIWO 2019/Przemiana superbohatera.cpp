// Hubert Jastrzębski | PIWO 2019/2020 (Przemiana superbohatera) | 2020-10-13
// https://szkopul.edu.pl/c/piwo-201920/p/prz/

#include <iostream>
#include <vector>

using namespace std;

const char vowels[6] = { 'a', 'e', 'i', 'o', 'u', 'y' };

int main()
{
    string a, b;
    cin >> a >> b;
    bool isTrue = true;

    for (int i = 0; i < a.size(); i++)
    {
        bool isVowel1 = false;
        bool isVowel2 = false;
        for (int j = 0; j < sizeof(vowels); j++)
            if (a[i] == vowels[j])
                isVowel1 = true;
        for (int j = 0; j < sizeof(vowels); j++)
            if (b[i] == vowels[j])
                isVowel2 = true;
        if (isVowel1 != isVowel2)
            isTrue = false;
    }

    if (isTrue && a.size() == b.size())
        cout << "TAK";
    else
        cout << "NIE";

    return 0;
}