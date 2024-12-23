// Hubert Jastrzębski | PIWO 2019/2020 (Cyfry parzyste i nieparzyste) | 2020-10-17
// https://szkopul.edu.pl/c/piwo-201920/p/cpn/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a, b, out = 0;
        cin >> a >> b;

        for (int j = a + 1; j < b; j++)
        {
            int even = 0;
            string js = to_string(j);
            switch (js.size())
            {
                case 1:
                    j = 9;
                    break;
                case 2:
                    if ((js[0] + js[1]) % 2 == 1)
                        out++;
                    break;
                case 3:
                    j = 1000;
                    break;
                case 4:
                    for (int k = 0; k < 4; k++)
                        if (js[k] % 2 == 0)
                            even++;
                    if (even == 2)
                        out++;
                    break;
                case 5:
                    j = 100011;
                    break;
            }
        }
        cout << out << "\n";
    }
}