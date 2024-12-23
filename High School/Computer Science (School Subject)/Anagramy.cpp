// Hubert Jastrzębski | Informatyka (Anagramy) | 2020-10-18
// https://classroom.google.com/u/1/c/MTkwNjU0OTAwNjgy/a/MTg2OTg5MTc0NDc2/details

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    // SITO
    vector<int> numbers;
    vector<int> primeNumbers = { 2, 3, 5, 7 };

    for (int i = 0; i < 120; i++)
        numbers.push_back(i + 2);

    for (int i = 2; i <= 7; i++)
        for (int j = 2; j < numbers.size(); j++)
            if (numbers[j] % i == 0)
                numbers[j] = 0;

    int temp = 4;
    for (int i = 4; i < ('z' - 'a'); i++)
    {
        while (numbers[temp] == 0)
            temp++;
        primeNumbers.push_back(numbers[temp]);
        temp++;
    }
    // KONIEC SITA


    string s, ss;
    getline(cin, s);
    getline(cin, ss);

    for (int i = 0; i < s.length(); i++)
        s[i] = tolower(s[i]);
    for (int i = 0; i < ss.length(); i++)
        ss[i] = tolower(ss[i]);

    unsigned long long is = 1, iss = 1;
    for (int i = 0; i < s.length(); i++)
        if (s[i] != ' ')
            is *= primeNumbers['z' - s[i] - 1];
    for (int i = 0; i < ss.length(); i++)
        if (ss[i] != ' ')
            iss *= primeNumbers['z' - ss[i] - 1];

    if (is == iss)
        cout << "TAK";
    else
        cout << "NIE";
    return 0;
}