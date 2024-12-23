// Hubert Jastrzębski | Satori C03 (Nawiasy) | 2021-01-18
// https://satori.tcs.uj.edu.pl/contest/6459992/problems/6670255

#include <iostream>
#include <stack>

using namespace std;
const char parentheseStart = '(';
const char parentheseEnd = ')';
const char squareBracketsStart = '[';
const char squareBracketsEnd = ']';
const char bracesStart = '{';
const char bracesEnd = '}';
string doo();

inline bool isBracketOpen(char c)
{
    if (c == parentheseStart || c == squareBracketsStart || c == bracesStart)
        return true;
    else
        return false;
}

inline bool isMatching(char a, char b)
{
    switch (a)
    {
        case parentheseStart:
            if (b == parentheseEnd)
                return true;
            return false;
        case squareBracketsStart:
            if (b == squareBracketsEnd)
                return true;
            return false;
        case bracesStart:
            if (b == bracesEnd)
                return true;
            return false;
    }
}

inline char getMatching(char c)
{
    switch (c)
    {
        case parentheseStart:
            return parentheseEnd;
        case squareBracketsStart:
            return squareBracketsEnd;
        case bracesStart:
            return bracesEnd;
    }
}

int main()
{
    int a;
    cin >> a;
    for (; a--;)
        cout << doo() << endl;
}

string doo()
{
    string in;
    cin >> in;
    stack<char> S;
    for (int i = 0; i < in.length(); i++)
    {
        char temp = in[i];
        if (isBracketOpen(temp))
            S.push(temp);
        else
        {
            if (S.empty())
                return "NIE";
            else
            {
                if (isMatching(S.top(), temp))
                    S.pop();
                else
                    return "NIE";
            }
        }
    }
    if (S.empty())
        return "TAK";
    else
    {
        string out = "";
        while (!S.empty())
        {
            out += getMatching(S.top());
            S.pop();
        }
        return out;
    }
}