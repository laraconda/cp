#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'

const ll INF = 1e18;


ll extgcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0ll) {
        x = 1ll; 
        y = 0ll; 
        return a;
    }
    ll x1, y1;
    ll g = extgcd(b, a%b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return g;
}

ll mod(ll x, ll m) {
    x %= m;
    x = (x < 0ll)? x+m: x;
    return x;
}


ll inv(ll m, ll a, bool& pos, ll& g, ll n, ll k, ll& y) {
    pos = true;
    ll x;
    g = extgcd(m, a, x, y);
    if (g == 0ll || (k - n) % g != 0ll) {
        pos = false;
        return 0ll;
    }
    // assert(x * m + a*y == g);
    x *= (k-n)/g;
    y *= (k-n)/g;
    return x;
}

ll findK(ll x, ll y, ll m, ll a, ll g) {
    ll K = -x / a;
    while (x + K*a < 0) K++;
    while (y - K*m >= 0) K++;
    ll newx = x + K*a;
    ll newy = y - K*m;
    return K;
}


int main() {
    ll n, m, a, k;
    string imp = "Impossible";
    cin >> n >> m >> a >> k;
    while (n || m || a || k) {
        if (m == 0ll && a == 0ll) {
            if (k == n) cout << n << endl;
            else cout << imp << endl;
        } else if (a == 0ll) {
            ll j = (k - n)/m;
            if (k == n + j*m) cout << k << endl;
            else cout << imp << endl;
        } else if (m == 0ll) {
            ll j = (n - k)/a;
            if (k + j*a == n) cout << n << endl;
            else cout << imp << endl;
        } else {
            bool pos;
            ll g;
            ll y;
            ll x = inv(m, a, pos, g, n, k, y);
            m/=g;
            a/=g;
            if (!pos) cout << imp << endl;
            else {
                /* cout << "g: " << g << endl;
                cout << "x: " << x << " y: " << y << endl;
                cout << "left:" << m*x + a*y << endl;
                cout << "right: " << (k-n)/g << endl;
                assert(m*x + a*y == (k-n)/g);
                */
                ll K = findK(x, y, m, a, g);
                // cout << "K: " << K << endl;
                ll newx = x + K*a;
                ll newy = y - K*m;
                newy *= -1;
                /*
                cout << "newx: " << newx << endl;
                cout << "newy: " << newy << endl;
                cout << "left: " << n + g*m*newx << endl;
                cout << "right: " << k + g*a*newy << endl;
                assert(n + g*m*newx == k + g*a*newy);
                */
                cout << n + g*m*newx << endl;
            }
        }
        cin >> n >> m >> a >> k;
    }
}
