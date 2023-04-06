#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int l=0;
        vector<ll> a;
        for (int i=0; i<n; i++) {
            int ai;
            cin >> ai;
            a.push_back(ai);
        }
        sort(a.begin(), a.end());
        ll m = 1e18 + 2; 
        bool p = false;
        for (int i=0; i<n-1; i++) {
            if (a[i] > 0) {
                if (m >= a[i]) l++;
                p = true;
                break;
            }
            m = min(m, abs(a[i] - a[i+1]));
            if (a[i] <= 0) l++;
        }
        if (a.back() <= 0 || m >= a.back() && !p) l++;
        cout << l << endl;
    }
}
