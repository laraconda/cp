#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> b(n+2);
        set<int> s;
        long long su = 0;
        for (int i=0; i<n+2; i++) {
            int bi;
            cin >> bi;
            b[i] = bi;
            su += bi;
            s.insert(bi);
        }
        int x = -1;
        int ex = -1;
        for (int i=0; i<n+2; i++) {
            if ((su - b[i]) % 2 == 0 && s.count((su - b[i])/2) == 1) {
                for (int j=0; j<n+2; j++) {
                    if (j == i) continue;
                    if (b[j] == (su - b[i])/2) {
                        x = i; ex = j;
                    }
                }
            }
        }
        if (x == -1 || ex == -1) {
            cout << -1 << endl;
        } else {
            for (int i=0; i<b.size(); i++) {
                if (i == ex || i == x) continue;
                cout << b[i] << " ";
            }
            cout << endl;
        }

    }
}
