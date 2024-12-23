// Hubert Jastrzębski | PIWO 2019/2020 (Halinka i książki) | 2020-10-12
// https://szkopul.edu.pl/c/piwo-201920/p/hik/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, max = 1;
    cin >> n;
    vector<vector<int>> numbers;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        bool isAdded = false;
        for (int j = 0; j < numbers.size() && numbers.size() != 0; j++)
        {
            if (numbers[j][0] == x)
            {
                numbers[j][1]++;
                if (numbers[j][1] > max)
                    max = numbers[j][1];
                isAdded = true;
                break;
            }
        }
        if (!isAdded)
        {
            vector<int> temp = { x, 1 };
            numbers.push_back(temp);
        }
    }

    int maxNumber = 0;
    for (int i = 0; i < numbers.size(); i++)
    {
        vector<int> temp = numbers[i];
        if (temp[1] == max)
            if (temp[0] > maxNumber)
                maxNumber = temp[0];
    }

    cout << maxNumber;

    return 0;
}