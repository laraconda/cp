#include <bits/stdc++.h>
using namespace std;

const int MXN = 1e6 + 6;
int dp[MXN];

void mfill(int n) {
    for (int i=0; i<=n; i++) {
        dp[i] = false;
    }
    dp[1] = true;
}

int main() {
    dp[1] = true;
    int n;
    while (cin >> n) {
        int m;
        cin >> m;
        vector<int> ms(m);
        for (int i=0; i<m; i++) {
            int mi;
            cin >> mi;
            ms[i] = mi;
        }
        for (int i=2; i<=n; i++) {
            for (int& mi : ms) {
                if (i - mi >= 1)
                    dp[i] = !dp[i - mi] || dp[i];
                if (i - mi == 0)
                    dp[i] = true;
            }
        }

        if (dp[n]) {
            cout << "Stan wins" << endl;
        } else {
            cout << "Ollie wins" << endl;
        }
        mfill(n);
    }
}
