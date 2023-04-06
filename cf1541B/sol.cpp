#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int c =0;
        for (int i=0; i<n; i++) cin >> a[i];
        for (int i=0; i<n; i++) {
            for (int z=1; z * a[i] <= 2*n; z++) {
                int j = a[i] * z - i - 2;
                if (j != i && j >= 0 && j < n && a[j] == z) c++;
            }
        }
        cout << c/2 << endl;
    }
}
