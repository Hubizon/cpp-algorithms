// Hubert Jastrzębski | PIWO 2019/2020 (Ozdoby choinkowe) | 2020-10-08
// https://szkopul.edu.pl/c/piwo-201920/p/ozd/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double a, b;
    cin >> a >> b;

    cout << ceil((double)(a * 2) / b) + ceil((double)(a * 5) / b) + ceil((double)(a * 8) / b);

    return 0;
}