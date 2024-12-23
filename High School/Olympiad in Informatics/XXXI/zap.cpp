// Hubert Jastrzębski | XXXI OI I (Zapobiegliwy student) | 2023-11-02
// https://sio2.mimuw.edu.pl/c/oi31-1/p/zap/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<array<int, 3>> V(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        V[i] = { b, a, i };
    }

    sort(V.begin(), V.end());

    vector<pair<int, int>> R1;
    int prev1 = 0, prev2 = 0, index1 = 0, index2 = 0;
    while (index1 < n) {
        auto [b, a, i] = V[index1]; index1++;
        if (prev2 > a) continue;
        int sub = -1, subE = -1;
        while (index2 < n) {
            auto [bsub, asub, isub] = V[index2]; index2++;
            if (prev1 > asub || index1 == index2) continue;
            sub = isub;
            subE = bsub;
            break;
        }
        if (sub != -1) {
            R1.push_back({ i, sub });
            prev1 = b;
            prev2 = max(b, subE);
        }
    }

    vector<int> R2;
    int prev = 0;
    for (auto [b, a, i] : V) {
        if (a >= prev) {
            R2.push_back(i);
            prev = b;
        }
    }

    if (R1.size() >= R2.size() - 1) {
        cout << R1.size() << '\n';
        for (auto& [i, sub] : R1)
            cout << i + 1 << ' ' << sub + 1 << '\n';
    }
    else {
        auto sub = R2.back();
        R2.pop_back();
        cout << R2.size() << '\n';
        for (auto& i : R2)
            cout << i + 1 << ' ' << sub + 1 << '\n';
    }
}