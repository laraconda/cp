#include <bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n+3);
        for (int i=0; i<n; i++) {
            int ri;
            cin >> ri;
            a[i] = ri;
        }
        int s=-1;
        int inter = -1;
        if (a[0] == 1) {
            s = n; 
        } else if (a[n-1] == 0) {
            s = 0; 
        } else {
            for (int i=0; i<n-1; i++) {
                if (a[i] == 0 && a[i+1] == 1) {
                    s = 0;
                    inter = i;
                    break;
                }
            }
        }

        if (s == -1) cout << s << endl;
        else if (inter == -1) {
            int x = s+1;
            for (int i=0; i<n+1; i++) {
                cout << x << " ";
                x++;
                if (x == n+2) x = 1;
            }
        } else {
            for (int i=1; i<=n; i++) {
                cout << i << " ";
                if (i-1 == inter) cout << n+1 << " ";
            }
        }
        cout << endl;
    }
}
