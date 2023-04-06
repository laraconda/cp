#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        map<int, int> m;
        vector<int> a(n);
        for (int i=0; i<n; i++) {
            cin >> a[i];
        }
        vector<int> oa(a);
        sort(oa.begin(), oa.end());
        for (int i=0; i<n; i++) {
            if (i != n - 1) {
                m[oa[i]] = oa[i+1];
            }else m[oa[i]] = 1e9 + 4;
        }
        int d = 1;
        for (int i=0; i<n; i++) {
            if (i != n -1) {
                if (m[a[i]] != a[i+1]) d++;
            }
        }
        if (d <= k) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
