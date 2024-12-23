// Hubert Jastrzębski | PIWO 2019/2020 (Raz od przodu, raz od tyłu) | 2020-10-11
// https://szkopul.edu.pl/c/piwo-201920/p/raz/30534/

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string word;
        cin >> word;
        for (int j = 0; j < word.length(); j++)
        {
            cout << word[j];
            if (j >= word.length() - j - 1)
                break;
            cout << word[word.length() - j - 1];
            if (word.length() % 2 == 0 && j >= word.length() - j - 2)
                break;
        }
        cout << endl;
    }

    return 0;
}