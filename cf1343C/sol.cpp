#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll NINF = -1e10;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int sign;
        ll mmax = NINF;
        ll s = 0;
        for (int i=0; i<n; i++) {
            ll ai;
            cin >> ai;
            if (i == 0) {
                sign = (ai > 0) ? 1 : -1;
                mmax = ai;
            }
            else if (sign > 0 && ai < 0 || sign < 0 && ai > 0) {
                s += mmax;
                mmax = ai;
                sign = (ai > 0) ? 1 : -1;
            } else {
                mmax = max(mmax, ai);
            } 
        }
        s += mmax;
        cout << s << endl;
    }
}
