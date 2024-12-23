// Hubert Jastrzębski | PIWO 2019/2020 (Plan lekcji) | 2020-10-13
// https://szkopul.edu.pl/c/piwo-201920/p/pla/

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;

    for (int i = 0; i < n; i++)
    {
        string c;
        cin >> c;
        s += c;
    }

    if (n == 1 && s[0] == '0')
        cout << 0;
    else
    {
        s.erase(s.begin(), s.begin() + s.find_first_of('1'));
        s.erase(s.begin() + s.find_last_of('1') + 1, s.end());
        while (s.find("00") != string::npos)
        {
            string temp = s;
            temp.erase(temp.begin(), temp.begin() + temp.find("00"));
            s.erase(s.begin() + s.find("00"), s.begin() + s.find("00") + temp.find('1'));
        }

        cout << s.size();
    }

    return 0;
}