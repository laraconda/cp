#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<int, ll> m;
        for (int i=0; i<n; i++) {
            int ai;
            cin >> ai;
            ll d = i - ai;
            m[d]++;
        }
        ll r = 0;
        for (auto x : m) {
            r += (x.second*(x.second-1))/2;
        }
        cout << r << endl;
    }
}
