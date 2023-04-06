#include <bits/stdc++.h>
using namespace std;


const int MAXN = 502;
long long dp[MAXN][MAXN];


long long get_two_columns(int n) {
    return n - (n/2 + 1);
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i=3; i<=n; i++) {
        long long twoc = get_two_columns(i);
        for (int j=i; j>0 && twoc > 0; j--, twoc--)
            dp[i][j] = 1;
        for (int j=3; j<i; j++)
            dp[i][j+1] += dp[i - j][j];
        
        for (int j=1; j<=n; j++) {
            dp[i][j] += dp[i][j-1];
        }
    }

    cout << dp[n][n] << endl;
}
