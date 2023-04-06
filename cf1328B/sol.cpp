#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll bs(ll l, ll h, ll k) {
    while (l <= h) {
        ll mid = l + (h - l)/2;
        ll res = mid * (mid - 1);
        if (res >= 2 * k) {
            h = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;

        ll p1 = bs(1, n, k);
        ll p2 = p1 - ((p1 * (p1-1))/2 - k + 1);

        string s;
        for (int i=0; i<n; i++) {
            if (n - i == p1) {
                s.push_back('b');
            } else if (n - i == p2) {
                s.push_back('b');
            } else {
                s.push_back('a');
            }
        }
        cout << s << endl;
    }
}
