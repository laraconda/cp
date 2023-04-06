#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, x;
        cin >> n >> x;
        vector<ll> ac(n);
        int k = -1;
        int ans = -1;
        for (int i=0; i<n; i++) {
            cin >> ac[i];
            if (i > 0)
                ac[i] += ac[i-1];
            if (ac[i] % x == 0) {
                if (k != -1) ans = max(i - k, ans); 
            } else {
                if (k == -1) k = i; 
                ans = max(ans, i+1);
            }
        }
        if (k == -1) ans = -1;
        cout << ans << endl;
    }
}
