#include <bits/stdc++.h>
using namespace std;

#define endl '\n';

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> w(n);
        vector<int> c(n);
        for (int i=0; i<n; i++) {
            cin >> w[i]; 
        }
        int m = 0;
        for (int tw=1; tw<=2*n; tw++) {
            for (int i=0; i<n; i++) c[i] = 0;
            int p = 0;
            for (int i=0; i<n; i++) {
                for (int j=0; j<n; j++) {
                    if (c[j] || c[i] || i == j) continue;
                    if (w[i] + w[j] == tw) {
                        c[i] = c[j] = 1;
                        p++;
                    }
                }
            }
            m = max(m, p);
        }
        cout << m << endl;
    }
}
