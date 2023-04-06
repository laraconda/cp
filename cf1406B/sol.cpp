#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a;
        ll mx=-1e9;
        for (int i=0; i<n; i++) {
            ll ai;
            cin >> ai;
            a.push_back(ai);
            mx = max(ai, mx);
        }
        sort(a.begin(), a.end(), [](ll x, ll y) {return abs(x) > abs(y);});
        ll r = a[0] * a[1] * a[2] * a[3] * a[4];
        if (r < 0) {
            for (int i=5; i<n; i++) {
                for (int j=0; j<5; j++) {
                    ll tmp = a[i];
                    for (int k=0; k<5; k++) {
                        if (k != j) tmp*=a[k];
                    }
                    r = max(r, tmp);
                }
            }
        }
        if (mx < 0) r = a[n-1] * a[n-2] * a[n-3] * a[n-4] * a[n-5];
        cout << r << endl;
    }
}
