#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll n, r, avg;
    cin >> n >> r >> avg;

    vector<pair<ll, ll>> gs;
    ll s = 0;
    for (int i=0; i<n; i++) {
        ll ai, bi;
        cin >> ai >> bi;
        s += ai;
        gs.push_back({bi, ai});
    }
    ll res = 0;
    ll left = (n * avg) - s;
    sort(gs.begin(), gs.end());
    int i=0;
    while (left > 0) {
        ll m = min(r - gs[i].second, left);
        res += m * gs[i].first;
        left -= m; 
        i++;
    }

    cout << res << endl;
}
