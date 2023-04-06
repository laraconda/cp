#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        bool p = true;
        int T = 0;
        int M = 0;
        vector<int> l(n);
        vector<int> r(n);
        for (int i=0; i<n; i++) {
            if (s[i] == 'T') {
                T++;
                l[i]++;
                r[i]++;
            } else M++;
        }
        for (int i=n-2; i>=0; i--) r[i] += r[i+1]; 
        for (int i=1; i<n; i++) l[i] += l[i-1]; 
        
        int mi =0;
        for (int i=0; i<n; i++) {
            if (s[i] == 'M') {
                mi++;
                if (l[i] < mi) p = false;  
            }
        } 
        mi =0;
        for (int i=n-1; i>=0; i--) {
            if (s[i] == 'M') {
                mi++;
                if (r[i] < mi) p = false;  
            }
        }
        if (2*M != T) p = false;
        if (p) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
}
