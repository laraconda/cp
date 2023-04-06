#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> co(n+1);
        int u = 0;
        int mmax = 0;
        for(int i=0; i<n; i++){
            int ai;
            cin >> ai;
            co[ai]++;
            if (co[ai] == 1) u++;
            if (co[ai] > mmax) mmax = co[ai];
        }

        int res;
        if (mmax < u) {
            res = mmax;
        } else if (mmax == u) {
            res = mmax - 1;
        } else {
            res = u;
        }

        cout << res << endl;


    }
}
