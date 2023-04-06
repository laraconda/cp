#include <bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        
        long long ai = 0;
        long long ap = 0;
        
        for (int i=0; i<n; i++) {
            int ni;
            cin >> ni;

            if (ni & 1) {
                ai++;
            } else
                ap++;
        }
        
        int m;
        cin >> m;

        long long bi = 0;
        long long bp = 0;
        for (int i=0; i<m; i++) {
            int mi;
            cin >> mi;

            if (mi & 1) {
                bi++;
            } else
                bp++;
        }

        long long res = 0;
        res += bp * ap;
        res += bi * ai;
        cout << res << endl;

    }
}
