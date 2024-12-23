// Hubert Jastrzębski | Diamentowy Indeks AGH XVII 1 (Słowo) | 2023-10-21
// https://www.diament.agh.edu.pl/wp-content/uploads/2024/01/Etap_I_zadania_Informatyka.pdf

#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

typedef unsigned long long ull;
const string VOWELS = "iyaeou";

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string S;
    cin >> S;
    int n = S.size();

    vector<ull> DP(110); DP[0] = 1;
    for (int i = 0, prev = -1; i < n; i++) {
        if (VOWELS.find(S[i]) != string::npos) {
            if (prev == -1)
                prev = i;
            else {
                int d = i - prev;
                for (int k = DP.size() - 1; k > 0; k--)
                    DP[k] = DP[k] + d * DP[k - 1];
                prev = i;
            }
        }
    }

    cout << accumulate(DP.begin(), DP.end(), 0ULL) - 1;
}