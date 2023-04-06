#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll n;
    cin >> n;

    vector<ll> ps(n);
    for (int i=0; i<n; i++) {
        ll ai;
        cin >> ai;
        ps[i] = ai;
        if (i > 0) {
            ps[i] += ps[i-1];
        }
    }

    ll t = ps.back();
    for (int i=0; i<n; i++) {
        if (ps[i] >= (double)t/2) {
            cout << i+1 << endl;
            break;
        }
    }

}
