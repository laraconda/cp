#include <bits/stdc++.h>
using namespace std;

const int MXN = 55;
int dp[MXN][MXN*MXN];
int plates[MXN][MXN*MXN];

void mclean() {
    for (int i=0; i<MXN; i++) {
        for (int j=0; j<MXN*MXN; j++) {
            dp[i][j] = 0;
            plates[i][j] = 0;
        }
    }
}

void bu(int n, int k, int p) {
    for (int a = 0; a <= p; a++) {
        dp[n-1][a] = plates[n-1][a];
    }
    for (int i=n-1; i>=0; i--) {
        for (int a = 0; a <= p; a++) {
            for (int b=0; b <= a; b++) {
                dp[i][a] = max(
                    dp[i][a],
                    plates[i][b] + dp[i + 1][a - b]
                );
            }
        }
    }
}

void cumsum(int n, int k) {
    for (int i=0; i<n; i++) {
        for (int j=2; j <= k ; j++) {
            plates[i][j] += plates[i][j-1]; 
        }
    }
}

int main() {
    int T;
    cin >> T;
    
    for (int t = 1; t <= T; t++) {
        mclean();
        int n, k, p;
        cin >> n >> k >> p;
        
        for (int i=0; i<n; i++) {
            for (int j=1; j<=k; j++) {
                int pij;
                cin >> pij;
                plates[i][j] = pij;
            }
        }
        
        cumsum(n, k);
        bu(n, k, p);
        
        int res = dp[0][p];
        cout << "Case #" << t << ": " << res << endl; 
    }
}
