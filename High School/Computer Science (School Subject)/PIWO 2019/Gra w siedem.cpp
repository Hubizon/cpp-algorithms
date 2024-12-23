// Hubert Jastrzębski | PIWO 2019/2020 (Gra w siedem) | 2020-10-12
// https://szkopul.edu.pl/c/piwo-201920/p/gr7/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int a, b, out = 0;
    cin >> a >> b;

    while(a < (b + 1))
    {
        if(a % 7 == 0)
            out++;
        else
        {
            string si = to_string(a);
            int sum = 0;
            for(int i = 0; i < si.length(); i++)
                sum += (si[i] - '0');
            if(sum % 7 == 0)
                out++;
        }
        a++;
    }

    cout << out;

    return 0;
}