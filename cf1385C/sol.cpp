#include <bits/stdc++.h>
using namespace std;

#define endl '\n';

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n+1);
        vector<int> l(n);
        a[0] = 1e7;
        for (int i=1; i<=n;i++) {
            cin >> a[i]; 
        }
        int tu = 0;
        int res;
        for (int i=n; i>0; i--) {
            res = i;
            int next = a[i-1];
            if (tu == 0 && next < a[i]) tu++;
            if (tu == 1 && next > a[i]) break;
        }
        cout << res - 1 << endl;
    }
}
