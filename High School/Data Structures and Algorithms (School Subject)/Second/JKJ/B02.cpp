// Hubert Jastrzębski | Satori B02 (Pudełka) | 2021-05-11
// https://satori.tcs.uj.edu.pl/contest/6941273/problems/6953567

#include <iostream>
#include <vector>
#include <set>

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
        vector<pair<int, int>> input(6);
        for (int i = 0; i < 6; i++)
            cin >> input[i].first >> input[i].second;

        bool is_possible = true;
        set<int> values;
        for (auto& in : input) {
            values.insert(in.first);
            values.insert(in.second);
        }

        if(values.size() > 3)
            cout << "NIEMOZLIWE\n";
        else {
            vector<int> count(6);

            for (int i = 0; i < 6; i++) {
                for (int j = 0; j < 6; j++) {
                    if (i == j) continue;
                    if ((input[i].first == input[j].first && input[i].second == input[j].second) || (input[i].first == input[j].second && input[i].second == input[j].first))
                        count[i]++;
                    else if ((input[i].second == input[j].first && input[i].first == input[j].second) || (input[i].second == input[j].second && input[i].first == input[j].first))
                        count[i]++;
                }
            }

            for (auto& c : count)
                if (!(c == 1 || c == 3 || c == 5))
                    is_possible = false;

            if (is_possible)
                cout << "MOZLIWE\n";
            else
                cout << "NIEMOZLIWE\n";
        }
    }
}