#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll mgcd(ll x, ll y) {
    if (y == 0) return x;
    return mgcd(y, x%y);
}

int mlen(ll n) {
    ll z = 1;
    for (int i=1; i<11; i++) {
       z*=10;
       if (n / z == 0) return i;
    }
}

bool isp(ll p) {
    if (p == 1 || p % 2 == 0) return false;
    if (p == 2) return true;
    for (int i=3; i<(int)sqrt(p); i+=2) if (p % i == 0) return false;
    return true;
}

ll prime(int k, ll avoid) {
    ll p = pow(10, k-1) + 1;
    while (!isp(p) || avoid == p) p++;
    return p;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
    int a, b, c;
    cin >> a >> b >> c;

    long long x, y;
    x = prime(a-c+1, -1);
    y = prime(b-c+1, x);
    ll m = pow(10, c-1);
    cout << x*m << " " << y*m << endl;
    }
}
