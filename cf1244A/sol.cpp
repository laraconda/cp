#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;

        int x = ceil((double)a/c);
        int y = ceil((double)b/d);

        if (x + y <= k) {
            cout << x << " " << y << endl; 
        } else {
            cout << -1 << endl;
        }
    }
}
