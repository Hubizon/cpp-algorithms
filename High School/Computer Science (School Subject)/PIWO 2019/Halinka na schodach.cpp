// Hubert Jastrzębski | PIWO 2019/2020 (Halinka na schodach) | 2020-10-17
// https://szkopul.edu.pl/c/piwo-201920/p/sch/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, stairsN = 0, lastNumber = 0;
    cin >> n;
    vector<int> stairs;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            stairs.push_back(lastNumber);
            stairsN++;
        }
        lastNumber = x;
    }

    cout << stairsN << "\n";
    for (int i = 1; i < stairsN; i++)
        cout << stairs[i] << " ";
    cout << lastNumber << "\n";
}