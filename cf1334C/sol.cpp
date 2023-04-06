#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'
#define fi first
#define se second

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<ll, ll>> ms;
        ll T = 0;
        for (int i=0; i<n; i++) {
             ll ai, bi;
             cin >> ai >> bi;
             ms.push_back({ai, bi});
        }
        for (int i=0; i<n; i++) {
            int j = (i == 0) ? n-1: i-1;
            T += max(0ll, ms[i].fi - ms[j].se);
        }
        ll res = 1e18;
        for (int i=0; i<n; i++) {
            int j = (i == 0) ? n-1: i-1;
            ll b = T - (max(0ll, ms[i].fi - ms[j].se)) + ms[i].fi; 
            res = min(res, b);
        }
        cout << res << endl;
    }
}
