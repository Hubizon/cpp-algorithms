// Hubert Jastrzębski | Satori C01 (Wojna) | 2020-12-21
// https://satori.tcs.uj.edu.pl/contest/6459992/problems/6626915

#include <iostream>
#include <deque>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (; n--;)
    {
        int a, b;
        cin >> a;
        deque<int> qa;
        deque<int> qb;
        for (int i = a; i--;) {
            int x;
            cin >> x;
            qa.push_back(x);
        }
        cin >> b;
        for (int i = b; i--;) {
            int x;
            cin >> x;
            qb.push_back(x);
        }
        int maxTurns, turnCounter = 0;
        cin >> maxTurns;
        for (; turnCounter < maxTurns && !qa.empty() && !qb.empty(); turnCounter++)
        {
            if (qa.front() > qb.front()) {
                qa.push_back(qb.front());
                qa.push_back(qa.front());
                qa.pop_front();
                qb.pop_front();
            } else {
                qb.push_back(qa.front());
                qb.push_back(qb.front());
                qb.pop_front();
                qa.pop_front();
            }
        }
        if (turnCounter == maxTurns)
        {
            cout << "A: ";
            for (int i = 0; i < qa.size(); i++)
                cout << qa[i] << " ";
            cout << "\nB: ";
            for (int i = 0; i < qb.size(); i++)
                cout << qb[i] << " ";
        }
        else
        {
            if (qa.empty())
                cout << "B ";
            else
                cout << "A ";
            cout << "wygrywa w turze " << turnCounter << ".";
        }
        cout << "\n";
    }
}