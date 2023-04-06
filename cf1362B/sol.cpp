#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        set<int> as;
        for (int i=0; i<n; i++) {
            cin >> a[i];
            as.insert(a[i]);
        }
        set<int> ks;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                ks.insert(a[i] ^ a[j]);
            }
        }
        
        int kans = -1;
        for (auto k : ks) {
            if (k == 0) continue;
            set<int> aa;
            bool ans = true;
            for (auto ai : as) {
                int x = k ^ ai;
                aa.insert(x);
                if (as.count(x) == 0) {break; ans = false;}
            }
            if (ans)
                ans = (aa == as);
            if (ans && (kans == -1 || kans > k))
                kans = k;
        }
        cout << kans << endl;
    }
}
