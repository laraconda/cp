#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void simp(ll& a, ll& b) {
    ll g = __gcd(a, b);
    while (g != 1) {
        a/=g;
        b/=g;
        g = __gcd(a, b);
    }
}

int main() {
    int n;
    cin >> n;

    vector<ll> as(n);
    vector<ll> bs(n);
    for (int i=0; i<n; i++) {
        cin >> as[i]; 
    } 
    for (int i=0; i<n; i++) {
        cin >> bs[i];
    }

    map<long double, int> mm;
    ll all = 0;

    for (int i=0; i<n; i++) {
        if (bs[i] == 0 && as[i] == 0) {
            all++; 
        } else if (as[i] == 0) {
            continue;
        } else {
            ll a = as[i];
            ll b = bs[i];
            simp(a, b);
            long double d = -(long double)b/a;
            mm[d]++;
        }
    }

    int res = 0;
    for (auto x : mm) {
        res = max(res, x.second);
    }
    res += all;
    cout << res << endl;
}
