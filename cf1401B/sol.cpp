#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c, d, e, f;
        cin >> a >> b >> c >> d >> e >> f;
        int x = 0;
        int y = f;
        x = min(c, e);
        c -= x;
        y -= a + c; 
        if (y < 0) y = 0;
        cout << 2*(x - y) << endl;
    }
}
