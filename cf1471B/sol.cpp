#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n, x;
        cin >> n >> x;
        ll total = 0;
        vector<pair<ll, ll>> a;
        for (int i=0; i<n; i++) {
            ll ai;
            cin >> ai;
            a.push_back({ai, 1});
        }
        int i=0;
        bool go = true;
        while (i < a.size()) {
            total += a[i].first * a[i].second; 
            if (a[i].first % x == 0 && go) a.push_back({a[i].first/x, x*a[i].second});
            else go = false;
            i++;
        }
        cout << total << endl;
    }
}
