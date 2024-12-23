// Hubert Jastrzębski | PIWO 2019/2020 (Potęga czwórki) | 2020-10-16
// https://szkopul.edu.pl/c/piwo-201920/p/po4/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, max = 0;
    cin >> n;
    vector<int> numbers;
    vector<int> dividers;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        numbers.push_back(a / 10);
        if ((a / 10) > max)
            max = (a / 10);
    }

    for (int i = 1; i < max; i *= 4)
        dividers.push_back(i);
    dividers.push_back(dividers[dividers.size() - 1] * 4);

    for (int i = 0; i < n; i++)
    {
        int temp = 0;
        while (numbers[i] >= dividers[temp])
            temp++;
        cout << dividers[temp - 1] << "\n";
    }
}