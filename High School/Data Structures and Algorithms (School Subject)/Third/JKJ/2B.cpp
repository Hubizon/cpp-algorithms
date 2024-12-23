// Hubert Jastrzębski | Satori 2B (Problem filozoficzny) | 2021-10-09
// https://satori.tcs.uj.edu.pl/contest/7079785/problems/7115809

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int z;
    cin >> z;
    while (z--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int cat = 0, san = 0, idk = 0;
        vector<int> positions = { 0 };
        auto pos = s.find("kk");
        while (pos != string::npos) {
            positions.push_back(++pos );
            pos = s.find("kk", pos);
        }
        positions.push_back(n);

        for (int i = 0; i < positions.size() - 1; i++) {
            int a = positions[i], b = positions[i + 1] - 1;
            if (s[a] == 'k' && s[b] == 'k')
                ++cat, ++san, idk += b - a - 3;
            else if (s[a] == 'k')
                san += b - a;
            else
                cat += b - a;
        }

        if (idk > 0 && idk >= abs(cat - san)) cout << '?';
        else if (cat == san) cout << '=';
        else cout << (cat > san ? 'K' : 'k');
        cout << '\n';
    }
}