// Hubert Jastrzębski | Satori B03 (Szybkie potęgowanie) | 2020-11-03
// https://satori.tcs.uj.edu.pl/contest/6459992/problems/6539743

#include <iostream>
#include <string>

using namespace std;

long long quickPowerMethod1(long long a, long long k, long long q)
{
    long long out = 1;

    while (k > 0)
    {
        a %= q;
        if (k % 2 == 1) {
            out *= a;
            out %= q;
        }
        a *= a;
        k /= 2;
    }
    return out;
}

string reverseDecimalToBinary(int x)
{
    if (x <= 0)
        return "0";

    string out = "";
    while (x != 0)
    {
        out += to_string(x % 2);
        x /= 2;
    }
    //reverse(out.begin(), out.end());
    return out;
}

long long quickPowerMethod2(long long a, long long k, long long q)
{
    string binary = reverseDecimalToBinary(k);
    long long out = 1;
    for (int i = 0; i < binary.size(); i++)
    {
        a %= q;
        if (binary[i] == '1')
            out *= a;
        a *= a;
        out %= q;
    }
    return out;
}

int main()
{
    long long n;
    cin >> n;
    for (int m = 0; m < n; m++)
    {
        long long a, k, q;
        cin >> a >> k >> q;
        cout << quickPowerMethod2(a, k, q) << endl;
    }
}}