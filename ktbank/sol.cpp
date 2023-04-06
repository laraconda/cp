#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;

    vector<int> bs(t);
    vector<pair<int, int>> ps(n);

    for (int i=0; i<n; i++) {
        int vi, ti;
        cin >> vi >> ti;
        ps[i] = {ti, vi};
    }

    sort(ps.begin(), ps.end());
    
    for (int i=0; i<n; i++) {
        int vi = ps[i].second;
        int ti = ps[i].first;

        int mmin = vi;
        int mmini = -1;
        for (int j=0; j<=ti; j++) {
            if (bs[j] < mmin) {
                mmin = bs[j];
                mmini = j;
            }
        }
        if (mmin < vi)
            bs[mmini] = vi;
    }

    long long res = 0;
    for (int& v : bs) {
        res += v;
    }
    cout << res << endl;
}
