#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int T;
    cin >> T;
    while (T--) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;

        ll x, y, x1, y1, x2, y2;
        cin >> x >> y >> x1 >> y1 >> x2 >> y2;

        bool beg = (x1 <= x && x <= x2 && y1 <= y && y <= y2);

        ll left = max(a - b, 0ll);
        ll right = max(b - a, 0ll);

        bool resx;
        if (left == 0 && right == 0 && (a > 0 || b > 0)) { 
            left = 1;
            bool resxa = (x1 <= x - left && x - left <= x2) &&
                (x1 <= x + right && x + right <= x2);

            left = 0;
            right = 1;
            bool resxb = (x1 <= x - left && x - left <= x2) &&
                (x1 <= x + right && x + right <= x2);

            resx = resxb || resxa; 
        } else {
            resx = (x1 <= x - left && x - left <= x2) &&
                (x1 <= x + right && x + right <= x2);
        }

        ll up = max(d - c, 0ll);
        ll down = max(c - d, 0ll);

        bool resy;
        if (up == 0 && down == 0 && (c > 0 || d > 0)) {
            up = 1;
            bool resya = (y1 <= y + up && y + up <= y2) &&
                (y1 <= y - down && y - down <= y2);

            up = 0;
            down = 1;
            bool resyb = (y1 <= y + up && y + up <= y2) &&
                (y1 <= y - down && y - down <= y2);
            resy = resya || resyb;
        
        } else {
            resy = (y1 <= y + up && y + up <= y2) &&
            (y1 <= y - down && y - down <= y2);
        }

        if (beg && resx && resy) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
