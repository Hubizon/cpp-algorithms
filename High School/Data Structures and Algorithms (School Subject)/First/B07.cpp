// Hubert Jastrzębski | Satori B07 (Malarze) | 2020-11-16
// https://satori.tcs.uj.edu.pl/contest/6459992/problems/6581163

#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

double function(double x, double y, double c, double w)
{
    double a = 1.0 / c;
    double b = (1.0 / sqrt(x * x - w * w)) + (1.0 / sqrt(y * y - w * w));
    return a - b;
}

double binarySearch(double x, double y, double c)
{
    double start = 0;
    double end = min(x, y);
    while (end - start >= 0.0001)
    {
        double middle = start + (end - start) / 2;
        if (function(x, y, c, middle) > 0)
            start = middle + 0.0001;
        else
            end = middle;
    }
    return start;
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (; n--;)
    {
        double x, y, c;
        cin >> x >> y >> c;
        cout << fixed << setprecision(3) << binarySearch(x, y, c) << "\n";
    }
}