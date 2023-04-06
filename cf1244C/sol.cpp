#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, p, w, d;
    cin >> n >> p >> w >> d;

    long long x, y, z;

    long long modx;
    long long modp = p % d;
    long long modw = w % d;
    cout << "modp: " << modp << " modw: " << modw << endl;
    if (modw == 0)
        modx = 0;
    else
        modx = modp / modw;

    x = min(p / w, n);
    cout << "x: " << x << " x mod d: " << x % d << " x mod w: " << x % w << endl;
    if (x % d > modx) {
        x -= (x % d) - modx;
    } else if (x % d < modx) {
        x = ((x/d) - 1) * d + modx;
    }
    cout << "new x: " << x << " x mod d: " << x % d << endl;
    if ((p - x * w) % d == 0)
        cout << "--------div--------" << endl;
    y = (p - x * w) / d;
    z = n - (x + y);
 
    cout << "x: " << x << " y: " << y << " z: " << y << endl;
    if (z < 0 || x < 0 || y < 0 || x*w + y*d != p) {
        cout << x*w + y*d - p << endl;
        cout << -1 << endl;
    } else {
        cout << x << " " << y << " " << z << endl;
    }
}
