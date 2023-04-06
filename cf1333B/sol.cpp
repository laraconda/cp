#include <bits/stdc++.h>
using namespace std;

const int MXI = 1e6;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        int fn = MXI;
        int fp = MXI;
        for (int i=0; i<n; i++) {
            int ai;
            cin >> ai;
            a[i] = ai;
            if (ai == 1 && fp == MXI) {
                fp = i;
            } else if (ai == -1 && fn == MXI) {
                fn = i; 
            }
        }
        
        bool pos = true;
        for (int i=0; i<n; i++) {
            int bi;
            cin >> bi;
            if (bi == a[i]) continue;
            if (bi > a[i] && i > fp) continue;
            if (bi < a[i] && i > fn) continue;
            pos = false;
        }

        if (pos) cout << "YES"; else cout << "NO";
        cout << endl;
    }
}
