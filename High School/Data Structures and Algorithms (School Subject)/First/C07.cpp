// Hubert Jastrzębski | Satori C07 (Urząd) | 2021-06-15
// https://satori.tcs.uj.edu.pl/contest/6459992/problems/6713992

#include <iostream>
#include <functional>
#include <algorithm>
#include <climits>
#include <vector>
#include <queue>

using namespace std;

struct Petent {
  int t, s, p, i;
  long long whenLeft = LLONG_MAX;
  bool operator<(const Petent& a) const { return t < a.t; }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, order = 0, indexJar = 0, indexTeo = 0;
    cin >> n;
    vector<Petent> petenci(n);
    for (auto& petent : petenci) {
        cin >> petent.t >> petent.s >> petent.p;
        petent.i = order++;
    }
    sort(petenci.begin(), petenci.end());

    priority_queue<int, vector<int>, function<bool(int, int)>>
        poczekalnia([&](int a, int b) { return petenci[a].p < petenci[b].p; });

    long long time = 0, timeJar = 0, timeTeo = 20, timeEnd;
    cin >> timeEnd;

    Petent* temp = new Petent();
    while (time < timeEnd && indexTeo < n)
    {
        while (!poczekalnia.empty() && petenci[poczekalnia.top()].whenLeft != LLONG_MAX) poczekalnia.pop();
        if (poczekalnia.empty()) {
            if (indexJar >= n) break;
            poczekalnia.push(indexJar);
            time = petenci[indexJar++].t;
            timeJar = max(time, timeJar);
            timeTeo = max(time, timeTeo);
        }
        else if (timeJar <= timeTeo) {
            temp = &petenci[poczekalnia.top()];
            timeJar += temp->s;
            temp->whenLeft = timeJar;
            poczekalnia.pop();
        }
        else {
            temp = &petenci[indexTeo++];
            if (temp->whenLeft != LLONG_MAX) continue;
            timeTeo += 2LL * temp->s + 20;
            temp->whenLeft = timeTeo - 20;
        }
        time = min(timeJar, timeTeo);
        while (indexJar < n && time >= petenci[indexJar].t)
            poczekalnia.push(indexJar++);
    }

    sort(petenci.begin(), petenci.end(), [&](Petent a, Petent b) { return a.i < b.i; });
    for (auto& petent : petenci)
        cout << min(petent.whenLeft, timeEnd) << '\n';
}