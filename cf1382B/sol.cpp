#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int c=-1;
        bool p = false;
        for (int i=0; i<n; i++) {
            int ai;
            cin >> ai;
            if (ai != 1 && p ==false) {
                c = i % 2;
                p = true;
            }
        }
        if (c == 0) cout << "First";
        else if (c == 1) cout << "Second";
        else if (n % 2) cout << "First";
        else cout << "Second";
        cout << endl;
    }
}
