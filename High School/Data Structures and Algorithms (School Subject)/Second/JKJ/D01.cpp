// Hubert Jastrzębski | Satori D01 (Hydra) | 2021-06-21
// https://satori.tcs.uj.edu.pl/contest/6941273/problems/7055943

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int z;
    cin >> z;
    while (z--)
    {
        long long liczbaUczestnikow, liczbaGlow, liczbaNog;
        cin >> liczbaUczestnikow >> liczbaGlow >> liczbaNog;
        cout << liczbaGlow - (2 * liczbaNog + liczbaUczestnikow - 13) / 3 << '\n';
    }
}