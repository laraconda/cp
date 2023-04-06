#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int x = n / k;
        bool pos = true;
        if (x != 0) {
            int r = n - x*k;
            if (r % 2 != 0) {
                if (k % 2 == 1 && x > 1) {
                    cout << "YES" << endl;
                    for (int i=1; i<k; i++) {
                        if (i % 2 == 1) {
                            cout << x+1 << " ";
                        } else cout << x-1 << " ";
                    }
                    cout << x + r << endl;
                } else pos = false;
            } else {
                cout << "YES" << endl;
                for (int i=1; i<k; i++) cout << x << " ";
                cout << x + r << endl;
            }
        } else pos = false;
        if (!pos) cout << "NO" << endl;
    }
}
