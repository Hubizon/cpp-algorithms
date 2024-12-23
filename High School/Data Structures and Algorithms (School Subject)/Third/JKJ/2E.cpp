// Hubert Jastrzębski | Satori 2E (Literackie zbiegi okoliczności) | placeholder
// https://satori.tcs.uj.edu.pl/contest/7079785/problems/7115853

#include <iostream>
#include <functional>
#include <vector>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int z;
    cin >> z;
    while (z--)
    {
        int n;
        cin >> n;

        ll result = 0;

        auto merge = [&](vector<ll>& arr, ll start, ll mid, ll end) {
          ll n1 = mid - start + 1, n2 = end - mid;

          vector<ll> L(n1);
          vector<ll> R(n2);

          for (int i = 0; i < n1; i++)
              L[i] = arr[start + i];
          for (int j = 0; j < n2; j++)
              R[j] = arr[mid + 1 + j];

          ll i = 0, j = 0, k = start;
          while (i < n1 && j < n2) {
              if (L[i] >= R[j])
                  arr[k++] = L[i++];
              else {
                  arr[k++] = R[j++];
                  result += n1 - i;
              }
          }

          while (i < n1)
              arr[k++] = L[i++];
          while (j < n2)
              arr[k++] = R[j++];
        };

        function<void(vector<ll>&, ll, ll)> mergeSort = [&](vector<ll>& arr, ll start, ll end) {
          if (end > start)
          {
              ll mid = (start + end) / 2;
              mergeSort(arr, start, mid);
              mergeSort(arr, mid + 1, end);
              merge(arr, start, mid, end);
          }
        };

        auto LP = [&](vector<ll>& arrOne, vector<ll>& arrTwo) {
          vector<ll> rev(n);
          for (int i = 0; i < n; i++)
              rev[arrOne[i] - 1] = i + 1LL;

          vector<ll> y(n);
          for (int i = 0; i < n; i++)
              y[i] = rev[arrTwo[i] - 1];

          mergeSort(y, 0, n - 1LL);

          ll r = result;
          result = 0;
          return r;
        };

        vector<ll> A(n), B(n), C(n);
        for (auto& a : A) cin >> a;
        for (auto& b : B) cin >> b;
        for (auto& c : C) cin >> c;

        ll lpOne = LP(A, B), lpTwo = LP(B, C), lpThree = LP(A, C);
        cout << (lpOne + lpTwo + lpThree - n * (n - 1LL) / 2) / 2 << '\n';
    }
}