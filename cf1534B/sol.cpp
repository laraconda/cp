#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n+2);
        for (int i=1; i<=n; i++) {
            cin >> a[i];
        }
        ll u = 0;
        for (int i=1; i<=n+1; i++) {
            u += abs(a[i] - a[i-1]);
        }
        for (int i=1; i<=n; i++) {
            u -= max(min(a[i] - a[i-1], a[i] - a[i+1]), 0);
        }
        cout << u << endl;
    }
}
