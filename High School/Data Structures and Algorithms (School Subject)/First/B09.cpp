// Hubert Jastrzębski | Satori B09 (Sierżant) | 2020-12-01
// https://satori.tcs.uj.edu.pl/contest/6459992/problems/6604336

#include <iostream>

using namespace std;

long long result = 0;
void merge(int*, int, int, int);

void mergeSort(int* arr, int start, int end) {
    if (end > start)
    {
        int mid = (start + end) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

void merge(int* arr, int start, int mid, int end)
{
    int n1 = mid - start + 1;
    int n2 = end - mid;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[start + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = start;
    while (i < n1 && j < n2) {
        if (L[i] >= R[j]) {
            arr[k++] = L[i++];
            //result += j;
        }
        else {
            arr[k++] = R[j++];
            result += (long long)n1 - i;
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];

    }
    while (j < n2) {
        arr[k++] = R[j++];

    }
    delete[] L;
    delete[] R;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (; n--;)
    {
        int a;
        cin >> a;
        int* arr = new int[a];
        for (int i = 0; i < a; i++) {
            int b;
            cin >> b;
            arr[i] = b;
        }
        mergeSort(arr, 0, a - 1);
        for (int i = 0; i < a; i++)
            cout << arr[i] << " ";
        cout << "\n" << result << "\n";
        result = 0;
    }
}