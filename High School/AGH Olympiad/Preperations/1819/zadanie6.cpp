// Hubert Jastrzębski | Diamentowy Indeks AGH 2018/2019 I (Zadanie 6) | 2023-03-08
// https://www.diament.agh.edu.pl/wp-content/uploads/2023/08/matematyka_i_2018_2019.pdf

#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <stack>

using namespace std;

typedef long long ll;

void solve() {
    string A;
    cin >> A;

    stack<int> S;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] == '[')
            S.push(i);
        else if (A[i] == ']') {
            auto pos = S.top(); S.pop();
            int cnt = A[pos + 1] - '0';
            string rep = A.substr(pos + 2, i - pos - 2);
            string toA;
            while (cnt--) toA += rep;
            string newA = A.substr(0, pos) + toA + A.substr(i + 1);
            A = newA;
            i = pos + toA.size() - 1;
        }
    }
        
    cout << A;
}

int main()
{
    solve();
}