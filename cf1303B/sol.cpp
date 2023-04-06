#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n, g, b;
        cin >> n >> g >> b;
        ll h = ceil((double)n/2); 
        ll p = g + b;
        ll np = (h % g == 0) ? h/g - 1: h/g;
        ll dg = np * p + (h - np * g);
        ll left = n - (h + np * b);
        if (left < 0) left = 0;
        ll d = dg + left;
        cout << d << endl; 
    }

}
