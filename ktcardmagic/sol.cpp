#include <bits/stdc++.h>
using namespace std;


const int MOD = 1e9 + 9;
const int MXN = 105;
long long dp[MXN*MXN][MXN];


void mfill() {
    for (int i=0; i<MXN*MXN; i++) {
        for (int j=0; j<MXN; j++) {
            dp[i][j] = -1;
        }
    }
}


long long W(int t, int n, int K) {
    if (t < n) return 0;
    if (t == n) return 1;
    if (n == 0) return 0;
    if (t == 0) return 0;
    if (dp[t][n] != -1) return dp[t][n];
    long long res = 0;
    for (int i=1; i<=K; i++) {
        res += W(t-i, n-1, K);
        res %= MOD;
    }
    dp[t][n] = res;
    return res;
}

int main() {
    int N, K, T;
    cin >> N >> K >> T;
    mfill();
    long long res = W(T, N, K);
    cout << res << endl;
}
