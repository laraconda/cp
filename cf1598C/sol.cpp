#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        map<ll, int> m;
        vector<ll> a;
        long double s = 0;
        for (int i=0; i<n; i++) {
            ll ai;
            cin >> ai;
            s += ai;
            m[ai]++;
            a.push_back(ai);
        }
        ll x = ((long double)n-2)*(s / n);
        ll c = 0;
        if ((long double)x / (n-2) == (long double) s / n) {
        for (ll ai : a) {
            ll d = (s - ai) - x;
            if (d >= 0) {
                c += m[d];
                if (d == ai) c--;
            }
        }
        }
        cout << c / 2 << endl;
    }
}
