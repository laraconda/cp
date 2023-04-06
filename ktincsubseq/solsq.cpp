#include <bits/stdc++.h>
using namespace std;

const int MXN = 103;
int a[MXN];
int dp[MXN];

int main() {
    int n;
    cin >> n;

    int ai;
    for (int i=0; i<n; i++) {
        cin >> ai;
        a[i] = ai;
        dp[i] = 1;
    }

    int mx = 1;
    int mxi = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<i; j++) {
            if (a[i] > a[j])
                dp[i] = max(dp[i], dp[j] + 1);

            if (dp[i] > mx) {
                mx = dp[i];
                mxi = i;
            }
        }
    }

    deque<int> ans;
    for (int i=mxi; i>=0; i--) {
        if (dp[i] == mx) {
            ans.push_front(a[i]);
            mx--;
        }
    }

    cout << ans.size() << endl;
    for (int i=0; i<ans.size()-1; i++)
        cout << ans[i] << " ";
    cout << ans[ans.size()-1] << endl;
}
