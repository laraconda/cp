#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = 1e9 + 7;

ll bp(ll n, ll k) {
    if (k == 0) return 1;
    if (k % 2 == 0) {
        ll r = bp(n, k/2);
        return (r * r) % M;
    } else {
        return (bp(n, k-1) * n) % M; 
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        cout << bp(n, k) << endl;
    }
}
