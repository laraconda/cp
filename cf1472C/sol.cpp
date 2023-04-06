#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<ll, ll>> a(n);
        for (int i=0; i<n; i++) {
            ll ai;
            cin >> ai;
            a[i].second = ai;
            a[i].first = ai;
        }
        ll m = 0;
        for (int i=n-1; i>=0; i--) {
            if (i + a[i].second < n)
                a[i].first += a[i + a[i].second].first;
            if (a[i].first > m) m = a[i].first;
        }
        cout << m << endl;
    }
}

