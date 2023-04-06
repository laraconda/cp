#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        int m = min(a, min(b, c));
        int s = a + b + c - 3*m;
        if (s % 3 == 0 && a + b + c > 6) {
            m -= s/6;
            if (s % 6 == 3) m-=2;
            if (m > -1 && m % 3 == 0) cout << "YES" << endl; 
            else cout << "NO" << endl;
        } else cout << "NO" << endl;
    }
}
