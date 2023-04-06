#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i=0; i<n; i++) {int ai; cin >> ai;}
        cout << n/2*6 << endl;
        for (int i=0; i<n; i+=2) {
            cout << 1 << " " << i+1 << " " << i+2 << endl;
            cout << 2 << " " << i+1 << " " << i+2 << endl;
            cout << 2 << " " << i+1 << " " << i+2 << endl;
            cout << 1 << " " << i+1 << " " << i+2 << endl;
            cout << 2 << " " << i+1 << " " << i+2 << endl;
            cout << 2 << " " << i+1 << " " << i+2 << endl;
        }
    }
}
