#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, m, k;
        cin >> n >> m >> k;
        bool pos = true;
        if (m < n-1) pos = false;
        if (m > (n*(n-1))/2) pos = false;
        if (k <= 1) pos = false;
        if (k <= 3 && m < ((n*(n-1))/2)) pos = false;
        if (n > 1) {
            if (n == 2 && m == n-1 && k < 3) pos = false;
            if (n > 2 && m == n-1 && k < 4) pos = false;
            if (m == ((n*(n-1))/2) && k <= 2) pos = false;
        }
        if (pos) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
