// Hubert Jastrzębski | PIWO 2019/2020 (Binarny podatek) | 2020-10-13
// https://szkopul.edu.pl/c/piwo-201920/p/bin/

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (s == "0")
            cout << "0\n";
        else if(s == "1")
            cout << "1\n";
        else
        {
            bool isEnd = false;
            string out = s;
            while (!isEnd)
            {
                int changes = 0;
                //out.erase(out.begin(), out.begin() + 1);

                for (int i = 0; i < out.size() - 1; i++)
                {
                    if (!(out[i] == '0' && out[i + 1] == '0') && i != 0)
                    {
                        changes++;
                        string temp(1, out[i]);
                        string temp2(1, out[i + 1]);
                        out.replace(i, 1, temp2);
                        out.replace(i + 1, 1, temp);
                    }
                }

                for (int i = 0; i < out.size() - 1; i++)
                {
                    if (out[i] == '1' && out[i + 1] == '1')
                    {
                        changes++;
                        out.replace(i, 1, "1");
                        out.replace(i + 1, 1, "");
                    }
                }

                if (changes == 0)
                    isEnd = true;
            }
            //out.erase(out.begin(), out.begin() + out.find('1'));
            cout << out << endl;
        }
    }

    return 0;
}