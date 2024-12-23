// Hubert Jastrzębski | PIWO 2019/2020 (Tulipany) | 2020-10-14
// https://szkopul.edu.pl/c/piwo-201920/p/tul/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> flowers;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        bool isAdded = false;
        for (int j = 0; j < flowers.size(); j++)
            if (flowers[j] == x)
                isAdded = true;
        if (!isAdded)
            flowers.push_back(x);
    }

    cout << 15000 - flowers.size();

    return 0;
}