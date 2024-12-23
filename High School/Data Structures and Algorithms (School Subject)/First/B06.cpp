// Hubert Jastrzębski | Satori B06 (Sortowanie) | 2020-11-23
// https://satori.tcs.uj.edu.pl/contest/6459992/problems/6566145

#include <iostream>

using namespace std;

void quickSort(int* arr, int start, int end)
{
    int mid = start + (end - start);
    if (arr[end] > arr[mid])
        swap(arr[end], arr[mid]);
    if (arr[start] > arr[mid])
        swap(arr[start], arr[mid]);
    int pivot = arr[mid];

    int i = start, j = end;
    while (i < j)
    {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j)
            swap(arr[i++], arr[j--]);
    }
    if (start < j)
        quickSort(arr, start, j);
    if (i < end)
        quickSort(arr, i, end);
}

int main()
{
    int n;
    cin >> n;
    for (int i = n; n--;)
    {
        int size;
        cin >> size;
        int* arr = new int[size];
        for (int j = 0; j < size; j++) {
            int x;
            cin >> x;
            arr[j] = x;
        }
        quickSort(arr, 0, size - 1);

        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
}