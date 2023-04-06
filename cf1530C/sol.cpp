#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i=0; i<n; i++) {
            cin >> a[i];
        }
        for (int i=0; i<n; i++) {
            cin >> b[i];
        }

        sort(a.begin(), a.end(), greater<int>());
        sort(b.begin(), b.end(), greater<int>());
        for (int i=1; i<n; i++) {
            a[i] += a[i-1];
            b[i] += b[i-1];
        }
        for (int i=0; i<10*n; i++) {
            int k = n + i;
            int c = k - floor((double)k / 4);
            int sa = 0;
            if (c - 1 - i >= 0) sa = a[c-1-i] + 100*i;
            else sa = 100*c;
            int sb = b[min(c-1, n-1)];
            if (sa >= sb) {
                cout << i << endl; 
                break;
            }
        }
    }
}
