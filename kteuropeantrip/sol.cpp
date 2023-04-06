#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long double ld;

struct Point {
    ld x;
    ld y;
    Point(ld x, ld y): x(x), y(y) {}
};

typedef struct Point Point;

vector<Point> ps;

ld dist(Point a, Point b) {
    return sqrt(pow(a.x - b.x, (ld)2) + pow(a.y - b.y, (ld)2));
}

ld cost(Point p) {
    ld c = 0;
    for (int i=0; i<3; i++)
        c += dist(ps[i], p);
    return c;
}

Point grad_desc(Point start) {
    Point m = start;
    ld alpha = 1200;
    ld mc = cost(m);
    vector<ld> ni = {-1, -1, 0, 1, 1, 1, 0, -1};
    vector<ld> nj = {0, 0, 1, 1, 0, -1, -1, -1};
    while (alpha > 0.0000001) {
        bool found = false;
        ld mx = m.x;
        ld my = m.y;
        for (int z=0; z<ni.size(); z++) {
            Point p = Point(mx + ni[z] * alpha, my + nj[z] * alpha);
            ld c = cost(p);
            if (c < mc) {
                found = true;
                mc = c;
                m = p;
            }
        }
        if (!found) alpha /= 2; 
    }
    return m;
}

int main() {
    int t = 3;
    while (t--) {
        ld x, y;
        cin >> x >> y;
        Point p = Point(x, y);
        ps.push_back(p);
    }

    Point start = Point(0, 0);
    Point res = grad_desc(start);
    cout << fixed << setprecision(6);
    cout << res.x << " " << res.y << endl;
}
