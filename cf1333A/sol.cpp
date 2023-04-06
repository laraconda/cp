#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        if (n*m % 2 != 0) {
            int count = 0;
            for (int i=0; i<n; i++) {
                for (int j=0; j<m; j++) {
                    string o = (count++ % 2 == 0) ? "B" : "W";
                    cout << o;
                }
                cout << endl;
            } 
        } else {
            int count = 0;
            for (int i=0; i<n; i++) {
                for (int j=0; j<m; j++) {
                    string o = (count++ % 2 == 0) ? "B" : "W";
                    if (j==1 && i == 0) o = "B";
                    cout << o;
                }
                cout << endl;
            } 
        }
    }
}
