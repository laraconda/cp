#include <bits/stdc++.h>
using namespace std;

bool dp[10][101];

int main() {
    int t;
    cin >> t;

    for (int d=0; d<10; d++) {
        for (int i=0; i<10; i++)
            dp[d][10*i + d] = true; 
    }
    for (int d=0; d<10; d++) {
        for (int i=0; i<100; i++) {
            if (!dp[d][i]) continue;
            for (int j=i; j<100; j++) {
                if (!dp[d][j]) continue;
                if (i + j > 100) continue;
                dp[d][i + j] = true;
            }
        }
    }

    

    while (t--) {
        int q, d;
        cin >> q >> d;
        int g = d*10;
        while(q--) {
            int ai;
            cin >> ai;
            if (ai >= g) cout << "YES" << endl;
            else if (dp[d][ai]) cout << "YES" << endl;
            else cout << "NO" << endl; 
        }
    }
}
