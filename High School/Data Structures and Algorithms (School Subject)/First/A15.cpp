// Hubert Jastrzębski | Satori A15 (Life) | 2020-10-19
// https://satori.tcs.uj.edu.pl/contest/6459992/problems/6517122

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int h, w, turns;
        cin >> h >> w;
        vector<vector<bool>> axis(h, vector<bool>(w));
        for (int j = 0; j < h; j++)
            for (int k = 0; k < w; k++)
            {
                char c;
                cin >> c;
                axis[j][k] = (c == 'o');
            }

        cin >> turns;
        for (auto& t : axis)
        {
            vector<bool>::iterator it;
            it = t.begin();
            t.insert(it, turns, 0);
            for (int k = 0; k < turns; k++)
                t.push_back(0);
        }
        vector<bool> temp((w + 2 * turns), 0);
        vector<vector<bool>>::iterator it;
        it = axis.begin();
        axis.insert(it, turns, temp);
        for (int j = 0; j < turns; j++)
            axis.push_back(temp);

        for (int t = 0; t < turns; t++)
        {
            vector<vector<int>> toAdd;
            vector<vector<int>> toRemove;
            int totalCellsAm = 0;

            for (int j = 1; j < axis.size() - 2; j++)
            {
                for (int k = 1; k < axis[j].size() - 2; k++)
                {
                    int cellsAm = axis[j - 1][k - 1] + axis[j - 1][k] + axis[j - 1][k + 1] + axis[j][k - 1]
                        + axis[j][k + 1] + axis[j + 1][k - 1] + axis[j + 1][k] + axis[j + 1][k + 1];
                    if (axis[j][k]) {
                        if (cellsAm != 2 && cellsAm != 3) {
                            vector<int> temp = { j, k };
                            toRemove.push_back(temp);
                        }
                        else
                            totalCellsAm++;
                    }
                    else {
                        if (cellsAm == 3) {
                            vector<int> temp = { j, k };
                            toAdd.push_back(temp);
                            totalCellsAm++;
                        }
                    }
                }
            }

            cout << totalCellsAm << endl;
            for (auto t : toAdd)
                axis[t[0]][t[1]] = true;
            for (auto t : toRemove)
                axis[t[0]][t[1]] = false;
        }
    }
}