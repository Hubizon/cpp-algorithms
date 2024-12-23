// Hubert Jastrzębski | Satori P06 (Pole) | 2023-06-17
// https://satori.tcs.uj.edu.pl/contest/7808974/problems/8598208

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <cmath>
#include <array>

using namespace std;

typedef double ld;
typedef pair<ld, ld> Point;
typedef array<ld, 3> Line;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << fixed << setprecision(20);

    int z;
    cin >> z;
    while (z--) {
        int n;
        cin >> n;

        int px, py;
        cin >> px >> py;

        vector<Line> V(n);
        for (int i = 0; i < n; i++) {
            ld ax, ay, bx, by;
            cin >> ax >> ay >> bx >> by;
            ax -= px, ay -= py, bx -= px, by -= py;
            V[i] = { -(by - ay), bx - ax, 0 };
            V[i][2] = V[i][0] * ax + V[i][1] * ay;
            if (V[i][2] < 0)
                V[i][0] *= -1, V[i][1] *= -1, V[i][2] *= -1;
        }

        if (n < 3) {
            cout << "INF\n";
            continue;
        }

        sort(V.begin(), V.end(), [&](auto& lhs, auto& rhs) {
          return atan2(lhs[1], lhs[0]) < atan2(rhs[1], rhs[0]); });

        V.insert(V.begin(), V.end() - 1, V.end());
        V.push_back(V[1]);

        auto intersect = [&](Line& a, Line& b) -> Point {
          ld Wx = a[2] * b[1] - b[2] * a[1];
          ld Wy = a[0] * b[2] - b[0] * a[2];
          ld W = a[0] * b[1] - b[0] * a[1];
          return { Wx / W, Wy / W };
        };

        auto ccw = [&](Point& a, Point& b) -> bool {
          return a.first * b.second - a.second * b.first > 0;
        };

        while (true) {
            bool isDel = false;
            vector<Line> V2;
            for (int i = 1; i < V.size() - 1; i++) {
                Point a = intersect(V[i - 1], V[i]);
                Point b = intersect(V[i], V[i + 1]);
                if (!ccw(a, b))
                    isDel = true;
                else
                    V2.push_back(V[i]);
            }
            if (!isDel || V2.empty())
                break;
            else {
                V = { V2.back() };
                for (int i = 0; i < V2.size(); i++)
                    V.push_back(V2[i]);
                V.push_back(V2.front());
            }
        }

        if (V.size() < 3) {
            cout << "INF\n";
            continue;
        }

        Point prev = intersect(V.front(), V.back());

        ld res = 0;
        for (int i = 1; i < V.size() - 1; i++) {
            Point p = intersect(V[i], V[i + 1]);
            res += abs(prev.first * p.second - prev.second * p.first);

            if (!ccw(prev, p)) {
                res = -1;
                break;
            }

            prev = p;
        }

        if (res == -1)
            cout << "INF\n";
        else
            cout << res / 2 << '\n';
    }
}