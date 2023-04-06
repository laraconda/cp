#include <bits/stdc++.h>
using namespace std;


int main() {
    long long n, p, w, d;
    cin >> n >> p >> w >> d;

    long long x, y, z;
    bool pos = false;
    for (int i = 0; i < w; i++) {
        if ((p - i * d) % w == 0) {
            x = (p - i * d) / w;
            if (x >= 0 && x + i <= n) {
                pos = true;
                y = i;
                z = n - (x + y);
                break;
            }
        }
    }

    if (pos)
        cout << x << " " << y << " " << z << endl;
    else
        cout << -1 << endl;
}
