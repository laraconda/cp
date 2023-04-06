#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
    ll n, k;
    cin >> n >> k;
    /*ll ans;
    ll x = ans / n;
    k = x * n + (ans % n) - x;
    k = ans + (ans % n) - ans  / n;
    */
   
    ll x = 0;
    while ((k + x) / n > x) x = (k + x) / n;
    cout << k + x << endl;
    }
}

