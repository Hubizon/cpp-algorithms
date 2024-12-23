// Hubert Jastrzębski | Satori C04 (Panorama) | 2021-01-26
// https://satori.tcs.uj.edu.pl/contest/6459992/problems/6701329

#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

bool myCmp(tuple<long long, long long, long long> a, tuple<long long, long long, long long> b)
{
    long long AxBy = get<1>(a) * get<2>(b);
    long long BxAy = get<2>(a) * get<1>(b);
    if (AxBy < BxAy)
        return true;
    if (AxBy > BxAy)
        return false;
    return get<2>(a) < get<2>(b);
}

int main()
{
    int a;
    cin >> a;
    for (; a--;)
    {
        int n;
        cin >> n;
        vector<tuple<long long, long long, long long>> mountains;
        for (int i = 0; i < n; i++)
        {
            long long x, y;
            cin >> x >> y;
            mountains.push_back(make_tuple(i, x, y));
        }
        sort(mountains.begin(), mountains.end(), myCmp);
        for (int i = 0; i < n; i++)
            cout << (get<0>(mountains[i]) + 1) << "\n";
    }
}