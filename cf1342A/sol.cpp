#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long p = 0;
        long long x, y, a, b;
        cin >> x >> y >> a >> b;
        if (x >= 0 && y >= 0) {
            p = b * min(x, y) + a * abs(x - y);
        } else if (x < 0 && y < 0) {
            p = b * max(x, y) + a * abs(x - y);
        }
        p = min(p, a*(x + y));
        cout << p << endl;
    }
}
