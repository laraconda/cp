#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n, u, v;
        cin >> n >> u >> v;
        vector<ll> a(n);
        for (int i=0; i<n; i++) {
            cin >> a[i];
        }
        bool entry = false;
        int M = 1e6 + 1;
        for (int i=0; i<n; i++) {
            if (i-1 >= 0) {
                if (abs(a[i-1] - a[i]) >= 2) entry = true;
            }
            if (i + 1 < n) {
                if (abs(a[i+1] - a[i]) >= 2) entry = true;
            }
        }
        if (!entry) {
            ll c = 1e15;
            for (int i=0; i<n; i++) {
                if (i-1 >= 0) {
                    int d = abs(a[i-1] - a[i]);
                    if (d == 1) {
                        if (a[i - 1] > a[i]) {
                            if (a[i] - 1 >= 0) c = min(c, v);
                            if (a[i] + 3 <= M) c = min(c, v*3);
                        } else {
                            if (a[i] - 3 >= 0) c = min(c, v*3); 
                            if (a[i] + 1 <= M) c = min(c, v);
                        } 
                        c = min(c, u);
                    } else if (d == 0) {
                        if (a[i] - 2 >= 0) c = min(c, v*2); 
                        if (a[i] + 2 <= M) c = min(c, v*2);
                        c = min(c, v+u);
                    }
                }
                if (i + 1 < n) {
                    int d = abs(a[i+1] - a[i]);
                    if (d == 1) {
                        if (a[i + 1] > a[i]) {
                            if (a[i] - 1 >= 0) c = min(c, v);
                            if (a[i] + 3 <= M) c = min(c, v*3);
                        } else {
                            if (a[i] - 3 >= 0) c = min(c, v*3); 
                            if (a[i] + 1 <= M) c = min(c, v);
                        } 
                        c = min(c, u);
                    } else if (d == 0) {
                        if (a[i] - 2 >= 0) c = min(c, v*2); 
                        if (a[i] + 2 <= M) c = min(c, v*2);
                        c = min(c, v+u);
                    }
                }
            }
            cout << c << endl;
        } else {
            cout << 0 << endl;
        }
    }
}
