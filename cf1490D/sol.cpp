#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        map<int, int> m;
        for (int i=0; i<n; i++) {
            int ai;
            cin >> ai;
            m[ai] = i;
        }
        vector<int> r(n);
        for (int i=n; i>=1; i--) {
            int p = m[i];
            for (int j = p-1; j>=0; j--) {
                if (r[j] < r[p]) break;
                r[j]++;
            }
            for (int j = p+1; j<n; j++) {
                if (r[j] < r[p]) break;
                r[j]++;
            }
        }
        for (int i=0; i<n; i++) {
            cout << r[i] << " ";
        }
        cout << endl;
    }
}
