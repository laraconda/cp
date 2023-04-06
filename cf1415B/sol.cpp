#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        set<int> s;
        vector<int> a(n);
        for (int i=0; i<n; i++) {
            int ai;
            cin >> ai;
            s.insert(ai);
            a[i] = ai;
        }
        int m = 1e9;
        for (int c : s) {
            int lm=0;
            int i=0;
            while (i < n) {
            if (a[i] != c) {
               lm++; 
               i += k; 
            } else i++;
            }
            m = min(m, lm);
        }
        cout << m << endl;
    }
}
