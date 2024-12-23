// Hubert Jastrzębski | PIWO 2019/2020 (Figury) | 2020-10-13
// https://szkopul.edu.pl/c/piwo-201920/p/fig/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> numbers;
    bool isTrue = false;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        numbers.push_back(x);
    }

    for (int i = 0; i < numbers.size() - 2; i++)
        if (numbers[i] + numbers[i+1] + numbers[i+2] == 3 && numbers[i] != numbers[i + 1])
            isTrue = true;

    if (isTrue)
        cout << "TAK";
    else
        cout << "NIE";

    return 0;
}