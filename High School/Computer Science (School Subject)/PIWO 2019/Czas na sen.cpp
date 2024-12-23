// Hubert Jastrzębski | PIWO 2019/2020 (Czas na sen) | 2020-10-05
// https://szkopul.edu.pl/c/piwo-201920/p/cza/

#include <iostream>
#include <string>

using namespace std;

void writeDifference(int);

int main()
{
    string time, sleepTime;
    cin >> time >> sleepTime;

    short hourDifference = stoi(time.substr(0, 2)) - stoi(sleepTime.substr(0, 2));
    short minuteDifference = stoi(time.substr(3, 2)) - stoi(sleepTime.substr(3, 2));

    if (minuteDifference < 0)
        hourDifference--;

    if (hourDifference < 0)
        writeDifference(24 + hourDifference);
    else
        writeDifference(hourDifference);
    cout << ":";

    if (minuteDifference < 0)
        writeDifference(60 + minuteDifference);
    else
        writeDifference(minuteDifference);

    return 0;
}

void writeDifference(int difference)
{
    if (difference < 10)
        cout << '0' << difference;
    else
        cout << difference;
}