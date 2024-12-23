// Hubert Jastrzębski | Satori B04 (Mnożenie) | 2020-11-02
// https://satori.tcs.uj.edu.pl/contest/6459992/problems/6552050

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int m = 0; m < n; m++)
    {
        string a, b;
        cin >> a >> b;
        bool isMinus = false;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        if (a.back() == '-') {
            a.pop_back();
            isMinus = true;
        }
        if (b.back() == '-') {
            b.pop_back();
            isMinus = !isMinus;
        }


        vector<int> vec(a.size() + b.size(), 0);
        for (int bi = 0; bi < b.size(); bi++)
            for (int ai = 0; ai < a.size(); ai++)
                vec[bi + ai] += (b[bi] - '0') * (a[ai]  - '0');

        int doAdd = false;
        for (int i = 0; i < vec.size(); i++)
        {
            int temp = vec[i] + doAdd;
            if (temp >= 10) {
                vec[i] = temp % 10;
                doAdd = temp / 10;
            }
            else {
                vec[i] = temp;
                doAdd = 0;
            }
        }

        string out = "";

        int i = vec.size() - 1;
        while (i != 0 && vec[i] == 0)
            i--;

        while (i >= 0) {
            out += vec[i] + '0';
            i--;
        }

        if (isMinus && out != "0")
            cout << "-";
        cout << out;

        cout << endl;
    }
}