#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, T;
        cin >> n >> T;
        int p = 0;
        for (int i=0; i<n; i++) {
            p %= 2;
            int ai;
            cin >> ai;
            if (T % 2 == 0) {
                if (ai < T/2) cout << 0 << " ";
                else if (ai > T/2) cout << 1 << " ";
                else cout << p++ << " ";
            } else {
                if (ai % 2 == 0) cout << 0 << " ";
                else cout << 1 << " ";
            }
        }
        cout << endl;
    }
}
