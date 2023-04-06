#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, p, k;
        cin >> n >> p >> k;
        
        vector<int> dp(n);
        vector<int> as(n);
        for (int i=0; i<n; i++) {
            cin >> as[i];
        }

        sort(as.begin(), as.end());
        
        for (int i=0; i<n; i++) {
            dp[i] = as[i];
        }

        for (int i=1; i<k-1; i++) {
            dp[i] += dp[i-1];
        }

        for (int i=k; i<n; i++) {
            dp[i] += dp[i-k];
        }

        int res = 0;
        for (int i=0; i<n; i++) {
            if (dp[i] <= p) res = i+1;
        }

        cout << res << endl;
    }
}
