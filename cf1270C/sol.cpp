#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll S = 0;
        ll X = 0;
        for (int i=0; i<n; i++) {
            ll ai;
            cin >> ai;
            S+=ai;
            X^=ai;
        }
        cout << 2 << endl;
        cout << X << " " << X+S << endl;
    }
}
