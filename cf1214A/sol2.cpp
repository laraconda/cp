#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll n, d, e;
    cin >> n >> d >> e;
    ll na = n;
    ll nb = n;
    e *= 5;

    ll mi = min(d, e);
    ll ma = max(d, e);

    
    ll a = na/ma;
    na -= a*ma;
    ll b = na/mi;
    na -= b*mi;

    a = nb/mi;
    nb -= a*mi;
    b = nb/ma;
    nb -= b*ma;
    cout << min(na, nb) << endl;
}
