// Hubert Jastrzębski | Satori A01 (Blackjack!) | 2020-09-07
// https://satori.tcs.uj.edu.pl/contest/6459992/problems/6460217

#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b;
    c = a + b;
    if(c == 21)
        cout<<"Blackjack!";
    else
        cout<<c;

    return 0;
}