// returns the convex hull of some points in the Cartesian coordinate system
// time complexity: O(n * log(n)), space: O(n)

typedef long long ll;
typedef pair<int, int> Point;

struct ConvexHull {
    vector<Point> P, A, B;

    ConvexHull(const vector<Point>& V) : P(V) {
        sort(P.begin(), P.end());
        A = create();
        reverse(P.begin(), P.end());
        B = create();
        A.insert(A.end(), B.begin(), B.end());
    }

    ll ccw(const Point& u, const Point& v) {
        return 1LL * u.first * v.second - 1LL * u.second * v.first;
    }

    Point getV(const Point& u, const Point& v) {
        return { v.first - u.first, v.second - u.second };
    }

    vector<Point> create() {
        vector<Point> D;
        Point s = P.front();
        for (auto p : P) {
            while (D.size() && ccw(getV(D.back(), s), getV(s, p)) <= 0)
                s = D.back(), D.pop_back();
            D.push_back(s);
            s = p;
        }
        return D;
    }

    ll area() {
        const ll minY = 1e9 + 1;
        ll res = 0;
        Point prev = A.back();
        for (int i = 0; i < A.size(); prev = A[i++])
            res += (prev.first - A[i].first) * (2 * minY + A[i].second + prev.second);
        return res; // / 2
    }
};
