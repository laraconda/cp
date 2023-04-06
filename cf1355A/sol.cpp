#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n';

int maxD(ll x) {
    int ma = -1;
    while (x > 0) {
        int d = x % 10;
        x/=10;
        ma = max(d, ma);
    }
    return ma;
}
int minD(ll x) {
    int mi = 10;
    while (x > 0) {
        int d = x % 10;
        x/=10;
        mi = min(d, mi);
    }
    return mi;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll a1, K;
        cin >> a1 >> K;

        ll ai = a1;
        ll res;
        for (int i=1; i<K; i++) {
            int md = minD(ai);
            if (md == 0) break;
            ai = ai + maxD(ai) * md; 
        }
        res = ai;
        cout << res << endl;
    }
}
