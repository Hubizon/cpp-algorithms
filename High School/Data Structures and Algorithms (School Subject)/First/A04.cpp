// Hubert Jastrzębski | Satori A04 (Liczby rzymskie) | 2020-09-25
// https://satori.tcs.uj.edu.pl/contest/6459992/problems/6469265

#include <iostream>

using namespace std;

string arabicToRoman(int, string, string, string);
int romanToArabic(string, char, char, char, int, char);

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string word;
        cin >> word;

        if (word.at(0) >= 48 && word.at(0) < 58)
        {
            switch (word.length())
            {
                case 4:
                    if (word.at(0) - 48 == 1)
                        cout << "M";
                    else
                        cout << "MM";
                    cout << arabicToRoman(word.at(1) - 48, "C", "D", "M") << arabicToRoman(word.at(2) - 48, "X", "L", "C") << arabicToRoman(word.at(3) - 48, "I", "V", "X") << endl;
                    break;

                case 3:
                    cout << arabicToRoman(word.at(0) - 48, "C", "D", "M") << arabicToRoman(word.at(1) - 48, "X", "L", "C") << arabicToRoman(word.at(2) - 48, "I", "V", "X") << endl;
                    break;

                case 2:
                    cout << arabicToRoman(word.at(0) - 48, "X", "L", "C") << arabicToRoman(word.at(1) - 48, "I", "V", "X") << endl;
                    break;

                default:
                    cout << arabicToRoman(word.at(0) - 48, "I", "V", "X") << endl;
                    break;
            }
        }
        else
        {
            int out = 0;

            for (int i = 0; i < word.length(); i++)
            {
                if (word.at(i) == 'M')
                    out += 1000;
                else
                    break;
            }

            out += romanToArabic(word, 'C', 'D', 'M', 100, 'X');
            out += romanToArabic(word, 'X', 'L', 'C', 10, 'I');
            out += romanToArabic(word, 'I', 'V', 'X', 1, 'Q');

            cout << out << endl;
        }
    }

    return 0;
}

string arabicToRoman(int x, string one, string five, string ten)
{
    string out = "";
    if (x == 0)
        return out;
    else if (x < 4)
        for (int i = 0; i < x; i++)
            out += one;
    else if (x == 4)
        out = one + five;
    else if (x < 9) {
        out = five;
        for (int i = 5; i < x; i++)
            out += one;
    }
    else
        out = one + ten;

    return out;
}

int romanToArabic(string word, char one, char five, char ten, int amountOfOne, char lesserOne)
{
    int out = 0;
    string temp = "";

    for (int i = 0; (i < word.length()); i++)
    {
        if (word.at(i) == five || word.at(i) == one)
        {
            if (i > 0) {
                if (word.at(i - 1) != lesserOne)
                    temp += word.at(i);
            }
            else
                temp += word.at(i);
            if ((word.at(i) == five || word.at(i) == one) && (i + 1) < word.length())
            {
                if (word.at(i + 1) == ten)
                {
                    temp += word.at(i + 1);
                    break;
                }
                else if (word.at(i + 1) != one && word.at(i + 1) != five)
                    break;
            }
        }
    }
    if (temp != "")
    {
        if (temp == (string(1, one) + five))
            out += 5 * amountOfOne - amountOfOne;
        else if (temp == (string(1, one) + ten))
            out += 9 * amountOfOne;
        else if (temp != (string(1, one) + five) && temp != (string(1, one) + ten) && temp.at(0) != five)
        {
            for (int i = 0; i < temp.length(); i++)
                if (temp.at(i) == one)
                    out += amountOfOne;
        }
        else
        {
            out += 5 * amountOfOne;
            for (int i = 1; i < temp.length(); i++)
                if (temp.at(i) == one)
                    out += amountOfOne;
        }
    }

    return out;
}