// Hubert Jastrzębski | Satori C06 (Wybory) | 2021-02-01
// https://satori.tcs.uj.edu.pl/contest/6459992/problems/6707534

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Partia {
  long long g, s, id;
};

struct MyCmp {
  bool operator() (Partia a, Partia b) const {
      if(a.g * (b.s + 1) < b.g * (a.s + 1))
          return true;
      if (a.g * (b.s + 1) > b.g * (a.s + 1))
          return false;
      if (a.g < b.g)
          return true;
      if (a.g > b.g)
          return false;
      if (a.id > b.id)
          return true;
      if (a.id < b.id)
          return false;
  }
};

int main()
{
    int a;
    cin >> a;
    for (; a--;)
    {
        long long n, m;
        cin >> n >> m;

        vector<int> V;
        priority_queue<Partia, vector<Partia>, MyCmp> Q;
        for (int i = 0; i < n; i++)
        {
            Partia partia;
            cin >> partia.g;
            partia.s = 0;
            partia.id = i;
            Q.push(partia);
            V.push_back(0);
        }

        for (int i = 0; i < m; i++)
        {
            Partia p = Q.top();
            Q.pop();
            p.s++;
            Q.push(p);
            V[p.id]++;
        }

        for (int i = 0; i < n; i++)
            cout << V[i] << endl;
    }
}