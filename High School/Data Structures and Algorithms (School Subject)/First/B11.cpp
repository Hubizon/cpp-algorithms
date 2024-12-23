// Hubert Jastrzębski | Satori B11 (Literackie zbiegi okoliczności) | 2020-12-09
// https://satori.tcs.uj.edu.pl/contest/6459992/problems/6620238

#include <iostream>

using namespace std;

long long result = 0;
void merge(long long*, long long, long long, long long);

void mergeSort(long long* arr, long long start, long long end) {
    if (end > start)
    {
        long long mid = (start + end) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, (long long) mid + 1, end);
        merge(arr, start, mid, end);
    }
}

void merge(long long* arr, long long start, long long mid, long long end)
{
    long long n1 = mid - start + 1;
    long long n2 = end - mid;

    long long* L = new long long[n1];
    long long* R = new long long[n2];

    for (long long i = 0; i < n1; i++)
        L[i] = arr[start + i];
    for (long long j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    long long i = 0, j = 0, k = start;
    while (i < n1 && j < n2) {
        if (L[i] >= R[j]) {
            arr[k++] = L[i++];
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

long long LP(long long* arrOne, long long* arrTwo, long long size)
{
    long long* rev = new long long[size];
    for (long long i = 0; i < size; i++)
        rev[arrOne[i] - 1] = (long long) i + 1;

    long long* y = new long long[size];
    for (long long i = 0; i < size; i++)
        y[i] = rev[arrTwo[i] - 1];

    mergeSort(y, 0, size - 1);

    delete[] rev;
    delete[] y;
    long long r = result;
    result = 0;
    return r;
}

void fill(long long* arr, long long size)
{
    for (long long i = 0; i < size; i++) {
        long long b;
        cin >> b;
        arr[i] = b;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long n;
    cin >> n;
    for (; n--;)
    {
        long long size;
        cin >> size;
        long long* arrX = new long long[size];
        fill(arrX, size);
        long long* arrY = new long long[size];
        fill(arrY, size);
        long long* arrZ = new long long[size];
        fill(arrZ, size);

        long long lpOne = LP(arrX, arrY, size);
        long long lpTwo = LP(arrY, arrZ, size);
        long long lpThree = LP(arrX, arrZ, size);
        cout << (lpOne + lpTwo + lpThree - size * (size - 1) / 2) / 2 << "\n";

        delete[] arrX;
        delete[] arrY;
        delete[] arrZ;
    }
}