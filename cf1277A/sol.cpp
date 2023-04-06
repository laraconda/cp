#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll> by;
const ll MXN = 1e9 + 3;

void gen() {
    for (int i=1; i<10; i++) {
        string ns;
        while (true) {
            string c = to_string(i);
            ns.push_back(c.back());
            ll n = stoll(ns);
            if (n >= MXN) break;
            by.push_back(n);
        }
    }

}

int main() {
    int t;
    cin >> t;

    gen();
    while (t--) {
        long long n;
        cin >> n;
    
        ll ans = 0;
        for (ll b : by) {
            if (b <= n) {
                ans++;
            }
        }
    
        cout << ans << endl;
    }
}
