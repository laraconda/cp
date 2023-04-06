#include <bits/stdc++.h>
using namespace std;

const int INF = 1e6;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> as(n);
        for (int i=0; i<n; i++) {
            cin >> as[i];
        }
        
        vector<int> mm(n+1, INF);
        int j=1;
        for (int i=0; i<m;i++) {
           int bi;
           cin >> bi;
           mm[bi] = j++;
        }

        for (int i=0; i<n; i++) {
            as[i] = mm[as[i]];
        }

        long long count = 0;
        vector<int> mmin(n);
        mmin[n-1] = as[n-1];

        if (as[n-1] != INF) count += 2 * ((n-1) - (as[n-1] - 1) ) + 1;
        for (int i=n-2; i>=0; i--) {
            mmin[i] = min(as[i], mmin[i+1]);
            if (as[i] != INF) {
                if (mmin[i] == as[i]) {
                    count += 2*(i - (as[i] - 1)) + 1;
                } else {
                    count++;
                }
            }
        }

        cout << count << endl;
    }
}
