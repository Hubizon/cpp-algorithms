// Hubert Jastrzębski | Satori A11 (Zielone Butelki) | 2020-10-27
// https://satori.tcs.uj.edu.pl/contest/6459992/problems/6476003

#include <iostream>
#include <string>

using namespace std;

bool isPrime(int);
const string buzz = "BUZZ";
const string firstLine = " green bottles standing on the wall.\n";
const string firstLineEnd = "1 green bottle standing on the wall.\n";
const string thirdLine = "and if one green bottle should accidentally fall,\n";
const string fourthLinePartOne = u8"there'd be ";
const string fourthLinePartTwo = " green bottles standing on the wall.\n\n";
const string fourthLineOne = u8"there'd be 1 green bottle standing on the wall.\n\n";
const string fourthLineEnd = u8"there'd be no green bottles standing on the wall.\n\n";

int main()
{
    int n;
    cin >> n;
    string temp;
    if (isPrime(n))
        temp = buzz;
    else
        temp = to_string(n);

    for (int i = n; i > 0; i--)
    {
        if (i > 1)
        {
            cout << temp << firstLine << temp << firstLine << thirdLine;
            if (isPrime(i - 1))
                temp = buzz;
            else
                temp = to_string(i - 1);
            if (i == 2)
                cout << fourthLineOne;
            else
                cout << fourthLinePartOne << temp << fourthLinePartTwo;
        }
        else
            cout << firstLineEnd << firstLineEnd << thirdLine << fourthLineEnd;
    }

    return 0;
}

bool isPrime(int x)
{
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;
    return true;
}