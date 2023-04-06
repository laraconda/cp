#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        long long last = -1;
        long long res = 0;
        for (int i=0; i<n; i++) {
            long long ai;
            cin >> ai;
            if (last != -1) {
                if (last > ai) res+= last - ai;
            }
            last = ai;
        }
        cout << res << endl;
    }
}
