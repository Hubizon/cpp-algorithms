// Hubert Jastrzębski | Satori A16 (Zbiory) | 2020-10-20
// https://satori.tcs.uj.edu.pl/contest/6459992/problems/6517154

#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;
long double coor[4][3];
long double triangleArea(int, int, int);

int main()
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 3; j++)
            cin >> coor[i][j];

    long double ABC = triangleArea(0, 1, 2);
    long double ACD = triangleArea(0, 2, 3);
    long double ABD = triangleArea(0, 1, 3);
    long double DBC = triangleArea(3, 1, 2);

    cout << fixed << setprecision(6) << ((long double)(ABC / 2) + (long double)(ACD / 2) + (long double)(ABD / 2) + (long double)(DBC / 2));
}

long double triangleArea(int a, int b, int c)
{
    long double ABx = (coor[b][1] - coor[a][1]) * (coor[c][2] - coor[b][2]) - (coor[b][2] - coor[a][2]) * (coor[c][1] - coor[b][1]);
    long double ABy = (coor[b][2] - coor[a][2]) * (coor[c][0] - coor[b][0]) - (coor[b][0] - coor[a][0]) * (coor[c][2] - coor[b][2]);
    long double ABz = (coor[b][0] - coor[a][0]) * (coor[c][1] - coor[b][1]) - (coor[b][1] - coor[a][1]) * (coor[c][0] - coor[b][0]);
    return sqrt(pow(ABx, 2) + pow(ABy, 2) + pow(ABz, 2));
}