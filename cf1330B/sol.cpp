#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> ni(n);
        int ma = -1;
        for (int i=0; i<n; i++) {
            cin >> ni[i];
            ma = max(ni[i], ma);
        }

        vector<pair<int,int>> res;

        int k=0;
        vector<int> b(n);
        vector<int> a(n);
        
        for (int i=0; i<ma; i++) {
           b[ni[i]]++; 
        }
        for (int i=ma; i<n; i++) {
           a[ni[i]]++; 
        }

        bool pos = true;
        for (int i=1; i<=ma; i++) {
            if (b[i] == 0) pos = false;
        }
        for (int i=1; i<=n-ma; i++) {
            if (a[i] == 0) pos = false;
        }

        if (pos) {
            k++;
            res.push_back({ma, n-ma});
        }

        for (int i=0; i<n; i++) {
            b[i] = 0;
            a[i] = 0;
        }
    
        for (int i=0; i<n-ma; i++) {
           b[ni[i]]++; 
        }
        for (int i=n-ma; i<n; i++) {
           a[ni[i]]++; 
        }

        pos = true;
        for (int i=1; i<=n-ma; i++) {
            if (b[i] == 0) pos = false;
        }
        for (int i=1; i<=ma; i++) {
            if (a[i] == 0) pos = false;
        }
        if (pos && n-ma != ma) {
            k++;
            res.push_back({n-ma, ma});
        }

        cout << k << endl;
        if (k) {
            for (int i=0; i<k; i++) {
                cout << res[i].first << " " << res[i].second << endl;
            }        
        }
        b.clear();
        a.clear();
    }
}
