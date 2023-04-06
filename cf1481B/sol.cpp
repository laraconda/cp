#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (int i=0; i<n; i++) {
            cin >> a[i];
        }

        bool f = false;
        while (k > 0 && n > 1) {
            if (f) break;
            for (int j=0; j<n-1; j++) {
                if (a[j] < a[j+1]) {
                    k--;
                    a[j]++;
                    if (k <= 0) {
                        f = true;
                        cout << j+1 << endl;
                    }
                    break;
                } else if (j == n-2) {
                    k = 0;
                    break;
                }
            }
        }
        if (!f) cout << -1 << endl;
    }
}
