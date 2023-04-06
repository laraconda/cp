#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> as(n+3);
        for (int i=0; i<n;i++) {
            cin >> as[i];
        }

        vector<vector<int>> ks(27, vector<int>(n));
        for (int ai=1; ai<=26; ai++) {
            ks[ai][0] = (as[0] == ai) ? 1 : 0;
            for (int i=1; i<n; i++) {
                ks[ai][i] += (as[i] == ai) ? 1 : 0;
                ks[ai][i] += ks[ai][i-1];
            }
        }

        vector<int> maxmid(n+2);
        if (n % 2 == 0) {
            for (int z=0; z<=n/2; z++) {
                for (int ai=1; ai<=26; ai++) {
                    int h = n/2 + z - 1; 
                    int l = n/2 - z - 1;
                    int rest = (l >= 0) ? ks[ai][l] : 0;
                    int val = ks[ai][h] - rest;    
                    maxmid[z] = max(maxmid[z], val);
                } 
            }
        } else {
            for (int z=1; z<=n/2; z++) {
                for (int ai=1; ai<=26; ai++) {
                    int h = n/2 + z - 1; 
                    int l = n/2 - z;
                    int rest = (l >= 0) ? ks[ai][l] : 0;
                    int val = ks[ai][h] - rest;    
                    maxmid[z] = max(maxmid[z], val);
                } 
            }
        }

        int maxval = 0;
        for (int ai=1; ai<=26; ai++) {
            for (int i=0; i<=n/2; i++) {
                int val1 = 0;
                int val2 = 0;
                if (i>0) {
                    val1 = ks[ai][i-1];
                    val2 = ks[ai][n-1] - ks[ai][n-1-i];
                }

                int z;
                if (n % 2 == 0)
                    z = (n - i*2)/2;
                else z = ((n - i*2) + 1) / 2;
                int val = val1 + val2 + maxmid[z];
                maxval = (maxval, val);
            }
        }
        cout << maxval << endl;
    }
}
