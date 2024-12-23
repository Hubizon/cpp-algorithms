// Hubert Jastrzębski | PIWO 2019/2020 (Największy ułamek) | 2020-10-16
// https://szkopul.edu.pl/c/piwo-201920/p/nau/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    //double numbers[3];
    double maxNumber = 0.0;
    string numerator, denominator;

    for (int i = 0; i < 3; i++)
    {
        int a, b;
        cin >> a >> b;
        //numbers[i] = a / b;
        double x = (double)a / b;
        if (x > maxNumber)
        {
            maxNumber = x;
            numerator = to_string(a);
            denominator = to_string(b);
        }
    }
    cout << numerator << " " << denominator;
}