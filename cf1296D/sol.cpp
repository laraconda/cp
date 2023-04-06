#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll a, b;

ll bs(int hi) {
    ll l = 0;
    ll h = 1e9 + 4;
    while (l <= h) {
        ll mid = l + (h - l)/2;
        ll r = a * mid + b * mid;
        if (r < hi) {
            l = mid + 1;
        } else {
            h = mid - 1; 
        }
    }
    return h;
} 

ll detk(int hi) {
    ll x = bs(hi);
    ll rem = (ll)hi - (a*x + b*x);
    return max(0ll, (ll)ceil((double)rem / a) - 1);
}

int main() {
    int n, k;
    cin >> n >> a >> b >> k;
    vector<ll> ks(n);
    for (int i=0; i<n; i++) {
        int hi;
        cin >> hi;
        ks[i] = detk(hi);
    }
    sort(ks.begin(), ks.end());
    int p = 0;
    ll kic = 0;
    for (int ki : ks) {
        kic += ki; 
        if (kic > k) {
            break;
        } else {
            p++;
        }
    }
    cout << p << endl;
}
