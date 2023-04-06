#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<int> ns(n);
        for (int i=0; i < n; i++) {
            int ni;
            cin >> ni;
            ns[i] = ni;
        }

        vector<int> fin;
        vector<int> picks;
        int kk = min(k, m-1);
        for (int i=0; i<=kk; i++) {
            int j = n - kk - 1 + i;
            int left = m - kk - 1;
            int jj = j - left;
            for (int ii=i; ii<n; ii++) {
                picks.push_back(max(ns[ii], ns[jj]));
                jj++;
                if (jj > j)
                    break;
            }

            int minp = 1e9 + 5;
            for (int a : picks) {
                if (a < minp)
                    minp = a;
            }
            picks.clear();
            fin.push_back(minp);
        }

        int res = -1;
        for (int a : fin) {
            if (a > res) {
                res = a;
            }
        }
        fin.clear();
        cout << res << endl;

    }
}
