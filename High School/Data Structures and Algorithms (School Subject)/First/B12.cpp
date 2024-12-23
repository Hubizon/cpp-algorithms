// Hubert Jastrzębski | Satori B12 (Naczelny Statystyk kontratakuje) | 2020-12-14
// https://satori.tcs.uj.edu.pl/contest/6459992/problems/6620269

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long n, sum = 0;
    cin >> n;
    long long* arr = new long long[n + 1];
    arr[0] = 0;
    for (long long i = 1; i <= n; i++) {
        long long x;
        cin >> x;
        sum += x;
        arr[i] = sum;
    }

    long long m;
    cin >> m;
    for (; m--;) {
        long long a, b;
        cin >> a >> b;
        cout << arr[b] - arr[a - 1] << "\n";
    }

    delete[] arr;
}