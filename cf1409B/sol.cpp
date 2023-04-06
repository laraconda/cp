#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll a, b, x, y, n;
        cin >> a >> b >> x >> y >> n;

        ll at = max(a - n, x);
        ll nt = n - (a - at);
        ll bt = max(y, b - nt);

        ll r1 = bt * at;
        
        bt = max(b - n, y);
        nt = n - (b - bt);
        at = max(x, a - nt);

        ll r2 = bt * at;
        cout << min(r1, r2) << endl;

    }
}
