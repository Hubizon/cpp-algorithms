// Hubert Jastrzębski | Satori B03 (Maraton filmowy) | 2021-05-11
// https://satori.tcs.uj.edu.pl/contest/6941273/problems/6953583

#include <iostream>
#include <vector>

using namespace std;

int main() // 0 - komedia, 1 - horror
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int z;
    cin >> z;
    while (z--)
    {
        int n, k;
        cin >> n >> k;
        string a, b;
        for (int i = 0; i < k; i++)
            cin >> a >> b;

        bool is_zero = true;
        while (n--) {
            if (is_zero) cout << '0';
            else cout << '1';
            is_zero = !is_zero;
        }

        cout << '\n';
    }
}