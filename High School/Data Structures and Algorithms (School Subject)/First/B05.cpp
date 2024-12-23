// Hubert Jastrzębski | Satori B05 (Naczelny Statystyk) | 2020-11-09
// https://satori.tcs.uj.edu.pl/contest/6459992/problems/6566125

#include <iostream>

using namespace std;

int binarySearch(int* arr, int x, int start, int end)
{
    while (start < end)
    {
        int middle = start + (end - start) / 2;
        if (arr[middle] < x) // can be changed
            start = middle + 1;
        else
            end = middle;
    }
    return start;
}

int main()
{
    int n;
    cin >> n;
    for (; n--;)
    {
        int a;
        cin >> a;
        int* arr = new int[a];
        for (int i = 0; i < a; i++)
        {
            int x;
            cin >> x;
            arr[i] = x;
        }
        int b;
        cin >> b;
        for (; b--;)
        {
            int x;
            cin >> x;
            int beggIndex = binarySearch(arr, x, 0, a);
            int endIndex = binarySearch(arr, x + 1, beggIndex, a);
            cout << endIndex - beggIndex << endl;
        }
    }
}