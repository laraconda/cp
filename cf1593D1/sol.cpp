#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    if (a == 0) return b;
    if (a == 1) return 1;
    return gcd(b % a, a);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        ll mi = 1e6 + 6;
        vector<ll> a(n);
        for (int i=0; i<n; i++) {
            cin >> a[i];
            mi = min(a[i], mi);
        }
        bool same = true;
        for (int i=0; i<n; i++) {
            a[i] = a[i] - mi;
            if (a[i] != 0) same = false;
        }
        if (same)
            cout << -1 << endl;
        else {
        ll g = gcd(a[0], a[1]);
        for (int i=2; i<n; i++) {
            g = gcd(g, a[i]);
        }
        cout << g << endl;
        }
    }
}
