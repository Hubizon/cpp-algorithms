// Hubert Jastrzębski | Satori B06 (Sortowanie) | 2024-11-16
// https://satori.tcs.uj.edu.pl/contest/6459992/problems/6566145

#include <iostream>

using namespace std;

void qsort(int arr[], int n) {
    if (n <= 1) return;

    int pivot = arr[n - 1];
    int i = 0, j = n - 2;
    while (i <= j) {
        if (arr[i] <= pivot) i++;
        else if (arr[j] >= pivot) j--;
        else swap(arr[i++], arr[j--]);
    }
    swap(arr[n - 1], arr[i]);

    qsort(arr, i);
    if (i != n - 1)
        qsort(arr + i + 1, n - i - 1);
}

struct Heap {
  int* arr;
  int n = 0;

  Heap(int arr[], int n) {
      this->arr = arr; // in place operations
      for (int i = 0; i < n; i++)
          push(arr[i]);
  }

  int top() {
      return arr[0];
  }

  void push(int x) {
      int pos = n++;
      arr[pos] = x;
      while (arr[(pos - 1) / 2] < x) {
          swap(arr[(pos - 1) / 2], arr[pos]);
          pos = (pos - 1) / 2;
      }
  }

  void pop() {
      swap(arr[0], arr[--n]);
      int pos = 0;
      while (true) {
          int maxPos = pos;
          int l = 2 * pos + 1, r = 2 * pos + 2;
          if (l < n && arr[l] > arr[maxPos])
              maxPos = l;
          if (r < n && arr[r] > arr[maxPos])
              maxPos = r;
          if (maxPos == pos)
              return;
          swap(arr[pos], arr[maxPos]);
          pos = maxPos;
      }
  }
};

void heapsort(int arr[], int n) {
    Heap heap(arr, n);
    for (int i = 0; i < n; i++)
        heap.pop();
}

int main() {
    int z;
    cin >> z;
    while (z--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        heapsort(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << ' ';
        cout << '\n';
    }
}