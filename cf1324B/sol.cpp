#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> as(n);
        for (int i=0; i<n; i++) {
            int ai;
            cin >> ai;
            as[i] = ai;
        }

        bool pos = false;
        for (int i=0; i<n; i++) {
            for (int j=i+2; j<n; j++) {
                if (as[i] == as[j]) {
                    pos = true;
                }
            }
        }
        if (pos) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl; 
        }
    }
}
