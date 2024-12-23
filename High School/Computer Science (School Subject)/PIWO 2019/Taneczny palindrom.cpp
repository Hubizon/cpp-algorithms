// Hubert Jastrzębski | PIWO 2019/2020 (Taneczny palindrom) | 2020-10-17
// https://szkopul.edu.pl/c/piwo-201920/p/tpa/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, a, b, price = 0;;
    cin >> n >> a >> b;
    vector <int> numbers;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        numbers.push_back(x);
    }

    for (int i = 0; i < numbers.size() / 2; i++)
    {
        if (numbers[i] + numbers[numbers.size() - i - 1] == 3)
        {
            cout << "NIE";
            return 0;
        }
    }


    for (int i = 0; i < numbers.size(); i++)
    {
        if(numbers[i] == 0)
            switch (numbers[i] + numbers[numbers.size() - i - 1])
            {
                case 0:
                    if (a >= b)
                        price += b;
                    else
                        price += a;
                    break;
                case 1:
                    price += a;
                    break;
                case 2:
                    if (numbers[i] == 0 || numbers[i] == 2)
                        price += b;
                    break;
                default:
                    break;
            }
    }
    cout << price;
}