#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


ll gauss(ll n) {
    if (n % 2 == 0)
        return n/2 * (n+1);
    else
        return n * (n+1)/2;
}

ll cb(int x, int y) {
   return (x+1) * gauss(y) + (y + 1) * gauss(x);
}

int main() {
    ll m, b;
    cin >> m >> b;

    ll X = m * b;
    ll res = 0;
    for (int i=0; i<=X; i++) {
       int y = floor(((double)i/m)*(-1) + b); 
       res = max(res, cb(i, y));
    }

    cout << res << endl;
}
