#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
        ll x;
        cin >> x;
        bool p = false;
        for (ll i=1; i<=(ll)1e4; i++) {
            ll d = x - pow(i, 3);
            if (d <= 0) break;
            double r = cbrt(d);
            if (floor(r) == r) {
                cout << "YES" << endl;
                p = true;
                break;
            }
        }
        if (!p) cout << "NO" << endl;
    }
}
