#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int e = 0;
        int o = 0;
        for (int i=0; i<n;i++) {
            int ai;
            cin >> ai;
            if (ai % 2 == 0) e++;
            else o++;
        }
        bool pos = true;
        if (o == 0) pos = false; 
        else if (max(x - e, 1) % 2 == 0) {
            if (o == x - e || e == 0) pos = false;
        }
        
        if (pos) cout << "YES" << endl;
        else cout << "NO" << endl;
        
    }
}
