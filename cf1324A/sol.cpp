#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int even = 0;
        int odd = 0;
        for (int i=0; i<n; i++) {
            int ai;
            cin >> ai;

            if (ai % 2 == 0) {
                even++;
            } else {
                odd++;
            }
        }

        if (even != 0 && odd != 0)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
}
