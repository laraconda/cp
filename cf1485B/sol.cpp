#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n, q, k;
    cin >> n >> q >> k;
    vector<int> a(n+2);
    a[0] = 0;
    a[n+1] = k+1;
    for (int i=1; i<=n; i++) {
        int ai;
        cin >> ai;
        a[i] = ai;
    }
    vector<ll> b(n+2);
    for (int i=1; i<=n; i++) {
        b[i] = b[i-1];
        b[i] += a[i + 1] - a[i-1] - 2;
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        int res = b[r-1] - b[l] + k - (a[r-1] + 1) + a[l+1] - 2;
        cout << res << endl;
    }
}
