#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i=0; i<n; i++) {
            cin >> a[i];
        }
        map<int, bool> m;
        int e = n;
        int z=n;
        for (int i=n-1; i>=0; i--) {
            for (int j=z; j>0; j--) {
                if (!m[j]) {z = j; break;}
            }
            if (a[i] == z) {
                for (int j=i; j<e; j++) {
                    m[a[j]] = true;
                    cout << a[j] << " ";
                }
                e = i;
            } 
        }
        cout << endl;
    }
}
