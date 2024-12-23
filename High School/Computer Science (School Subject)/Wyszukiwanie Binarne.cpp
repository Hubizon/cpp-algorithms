// Hubert Jastrzębski | Informatyka (Wyszukiwanie binarne) | 2021-10-19
// https://classroom.google.com/u/1/c/MTkwNjU0OTAwNjgy/a/MTUxNTgyNjI2OTQ4/details

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarnie(vector<int>, int, int, int);

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> numbers;

    for (int i = 0; i < n; i++)
        numbers.push_back(rand() % n + 1);

    sort(numbers.begin(), numbers.end());


    //ITERACYJNIE:
    bool isFound = false;
    for (int i = 0; i < n && !isFound; i++)
        if (numbers[i] == x) {
            cout << "Znaleziono liczbe! Jest to indeks " << i << "\n\n";
            isFound = true;
        }
    if (!isFound)
        cout << "Niestety nie znaleziono liczby.\n\n";

    /* // BINARNIE (wersja 1):
    bool isFound2 = false;
    int leftSide = 0, rightSide = numbers.size() - 1, tempIndex;
    while (leftSide <= rightSide)
    {
        tempIndex = (leftSide + rightSide) / 2;
        if (numbers[tempIndex] < x)
            leftSide = tempIndex + 1;
        else if (numbers[tempIndex] > x)
            rightSide = tempIndex - 1;
        else {
            cout << "Znaleziono liczbe! Jest to indeks " << tempIndex  << "\n\n";
            isFound2 = true;
        }
    }
    if (!isFound2)
        cout << "Niestety nie znaleziono liczby." << "\n\n"; */


    //BINARNIE (wersja 2):
    int binary = binarnie(numbers, x, 0, numbers.size() - 1);
    if (binary == -1)
        cout << "Niestety nie znaleziono liczby.\n\n";
    else
        cout << "Znaleziono liczbe! Jest to indeks " << binary << "\n\n";
}

int binarnie(vector<int> numbers, int x, int leftSide, int rightSide)
{
    if (leftSide <= rightSide)
    {
        int tempIndex = (leftSide + rightSide) / 2;
        if (numbers[tempIndex] < x)
            return binarnie(numbers, x, tempIndex + 1, rightSide);
        else if (numbers[tempIndex] > x)
            return binarnie(numbers, x, leftSide, tempIndex - 1);
        else
            return tempIndex;
    }

    return -1;
}

