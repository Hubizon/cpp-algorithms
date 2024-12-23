// Hubert Jastrzębski | Satori C08 (Test na inteligencję) | 2021-02-15
// placeholder

#include <iostream>
#include <algorithm>
#include <vector>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    int a;
    cin >> a;
    while (a--)
    {
        int An;
        cin >> An;
        vector<int> A(An);
        for (int& a : A)
            cin >> a;
        int Bn, i = 0;
        cin >> Bn;
        vector<vector<int>> B(Bn);
        unordered_map<int, vector<int>> K;
        for (auto& b : B) {
            int bn;
            cin >> bn;
            b = vector<int>(bn);
            for (int& vb : b)
                cin >> vb;
            K[b.back()].push_back(i++);
        }

        reverse(A.begin(), A.end());
        for (int a : A) {
            A.pop_back();
            vector<int> temp = K[a];
            K.erase(a);
            for (int& t : temp) {
                B[t].pop_back();
                if (!B[t].empty())
                    K[B[t].back()].push_back(t);
            }
        }

        for (auto& b : B) {
            if (b.empty())
                cout << "TAK\n";
            else
                cout << "NIE\n";
        }
    }
}