// Hubert Jastrzębski | Diamentowy Indeks AGH XVII 1 (Działki) | 2023-10-21
// https://www.diament.agh.edu.pl/wp-content/uploads/2024/01/Etap_I_zadania_Informatyka.pdf

#include <iostream>
#include <vector>

using namespace std;    

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    vector<long long> V(n);
    for (auto& v : V)
        cin >> v;

    vector<long long> DP(n);
    DP[0] = V[0]; DP[1] = V[1];
    DP[2] = V[0] + V[2];
    for (int i = 3; i < n; i++) 
        DP[i] = V[i] + max(DP[i - 2], DP[i - 3]);

    cout << max(DP[n - 2], DP[n - 1]);
}