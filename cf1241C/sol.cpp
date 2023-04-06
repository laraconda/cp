#include <bits/stdc++.h>
using namespace std;

const int MXN = 2e5 + 5;
long long t3[MXN];
long long t2[MXN];
long long t1[MXN];
long long cums[MXN];

void mclean() {
    for (int i=0; i<MXN; i++) {
        t3[i] = 0;
        t2[i] = 0;
        t1[i] = 0;
        cums[i] = 0;
    }
}

int main() {
    int q;
    cin >> q;

    while (q--) {
        mclean();
        
        int n;
        cin >> n;
        vector<int> ts;
        for (int i=0; i<n; i++) {
            int ti;
            cin >> ti;
            ts.push_back(ti);
        }

        sort(ts.begin(), ts.end(), greater<int>());
        cums[1] = ts[0];
        for (int i=2; i<=ts.size(); i++) {
            cums[i] = cums[i-1] + ts[i-1];
        }

        int x, a;
        cin >> x >> a;
        int y, b;
        cin >> y >> b;
        long long k;
        cin >> k;

        int mx;
        int mxjump;
        int mn;
        int mnjump;
        
        if (x >= y) {
            mx = x;
            mxjump = a;
            mn = y;
            mnjump = b;
        } else {
            mx = y;
            mxjump = b;
            mn = x;
            mnjump = a;
        }

        long long lcm = (long long)a*b / __gcd(a, b); 
        for (int i=1; i <= n; i++) {
            t3[i] = t3[i-1];
            if (i % lcm == 0)
                t3[i] += 1;
        }
        
        for (int i=1; i <= n; i++) {
            t2[i] = t2[i-1];
            if (i % lcm == 0) continue;
            if (i % mxjump == 0)
                t2[i] += 1;
        }
        
        for (int i=1; i <= n; i++) {
            t1[i] = t1[i-1];
            if (i % lcm == 0) continue;
            if (i % mnjump == 0)
                t1[i] += 1;
        }

        int res = -1;
        for (int i=1; i<=n; i++) {
            int lastj = 0;
            long long s = 0;
            s += (x + y) * cums[t3[i]] / 100;
            lastj = t3[i];
            s += mx * (cums[lastj + t2[i]] - cums[lastj]) / 100;
            lastj += t2[i];
            s += mn * (cums[lastj + t1[i]] - cums[lastj]) / 100;
            if (s >= k) {
                res = i;
                break;
            }
        }

        cout << res << endl;

    }
}
