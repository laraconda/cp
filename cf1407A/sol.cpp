#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int o = 0;
        int z;
        for (int i=0; i<n; i++) {
            int ai;
            cin >> ai;
            o += ai;
        }
        z = n - o;
        if (o > z) {
            int k = o;
            if (o % 2 != 0) k--; 
            cout << k << endl;
            while (k--) cout << 1 << " ";
        } else {
            int k = z;
            cout << k << endl;
            while (k--) cout << 0 << " ";
        }
        cout << endl;
    }
}
