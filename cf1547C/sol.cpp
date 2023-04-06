#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k, n, m;
        cin >> k >> n >> m;

        vector<int> a(n);
        vector<int> b(m);
        for (int i=0; i<n; i++) {
            cin >> a[i];
        }
        for (int i=0; i<m; i++) {
            cin >> b[i];
        }
        int j = 0, i = 0;
        bool p = true;
        vector<int> sol;
        while (i < n || j < m) {
            bool f = false;
            if (i < n) {
                if (a[i] == 0) {
                    k++;
                    i++;
                    sol.push_back(0);
                    f = true;
                } else if (a[i] <= k) {
                    sol.push_back(a[i]);
                    f = true;
                    i++;
                }
            }
            if (j < m) {
                if (b[j] == 0) {
                    f = true;
                    k++;
                    j++;
                    sol.push_back(0);
                } else if (b[j] <= k) {
                    sol.push_back(b[j]);
                    f = true;
                    j++;
                }
            }
            if (!f) {p = false; break;}
        }
        if (!p) cout << -1;
        else for (int x : sol) cout << x << " ";
        cout << endl;
    }
}
