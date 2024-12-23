// Hubert Jastrzębski | PIWO 2019/2020 (Idealna para) | 2020-10-13
// https://szkopul.edu.pl/c/piwo-201920/p/ipa/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
    int n, min = 300, out = 0;
    cin >> n;
    vector<int> numbers;
    vector<int> minNumbers;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        numbers.push_back(x);
    }

    sort(numbers.begin(), numbers.end());

    for (int i = 1; i < numbers.size(); i++)
        if (abs(numbers[i] - numbers[i - 1]) < min)
            min = abs(numbers[i] - numbers[i - 1]);

    for (int i = 0; i < numbers.size(); i++)
    {
        for(int j = 0; j < numbers.size(); j++)
            if(abs(numbers[i] - numbers[j]) == min && i != j)
                out++;
    }

    cout << out / 2;
    return 0;
}