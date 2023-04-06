#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    vector<ll> HH(52);
    ll x = 1;
    for (int i=0; i<52; i++) {
        HH[i] = x;
        x *= 2;
    }
    while (t--) {
        ll h, p;
        cin >> h >> p;
        vector<ll> H(HH);
        ll times = 0;
        for (int i=0; i<h; i++) {
            if (HH[i] <= p) {
                times++;
                continue;
            }
            times += ceil((double)H[i]/p); 
            ll last = H[i] % p;
            if (p >= H[i]) last = 0;
            ll spare = p - last;
            if (last == 0) spare = 0;
            ll rnext = (HH[i] - last) * 2;
            H[i+1] -= min(spare, rnext);
            if (H[i+1] < 0) H[i+1] = 0;
        }
        cout << times << '\n';
    }
}
