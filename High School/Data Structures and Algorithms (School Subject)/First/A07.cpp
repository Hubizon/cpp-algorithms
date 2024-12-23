// Hubert Jastrzębski | Satori A07 (Algorytm Euklidesa) | 2020-09-21
// https://satori.tcs.uj.edu.pl/contest/6459992/problems/6469309

#include <iostream>

using namespace std;

long NWD(long, long);

int main()
{
    long n;
    cin >> n;

    for (long i = 0; i < n; i++)
    {
        long a, b;
        cin >> a >> b;
        cout << NWD(a, b) << "\n";
    }
}

long NWD(long a, long b)
{
    if(b == 0)
        return a;
    else
        return NWD(b, (a % b));
}