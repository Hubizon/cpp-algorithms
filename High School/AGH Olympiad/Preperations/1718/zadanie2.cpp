// Hubert Jastrzębski | Diamentowy Indeks AGH 2017/2018 I (Zadanie 2) | 2023-03-04
// https://www.diament.agh.edu.pl/wp-content/uploads/2023/08/matematyka_i_2017_2018.pdf

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

void solve() {
    int n;
    cin >> n;

    vector<int> Fib = { 1, 1 };
    while (Fib.back() < 1e6)
        Fib.push_back(*Fib.rbegin() + *++Fib.rbegin());

    vector<bool> V(1e7);
    for (int i = 0; i < Fib.size(); i++) {
        ll x = 0;
        for (int j = i; j < Fib.size(); j++) {
            x += Fib[j];
            V[x] = true;
        }
    }

    for (int i = n + 1; i < V.size(); i++) {
        if (!V[i]) {
            cout << i;
            exit(0);
        }
    }
}


int main()
{
    solve();
}
