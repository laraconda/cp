#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> h(n);
        vector<ll> hc(n);
        for (int i=0; i<n; i++) {
            int hi;
            cin >> hi;
            h[i] = hi;
        }
        sort(h.begin(), h.end());
        if (n == 2) {
            for (int hi : h) cout << hi << " ";
            cout << endl;
            continue;
        }
        hc[0] = 0;
        for (int i=1; i<n; i++) {
            hc[i] = hc[i-1] + (h[i] > h[i-1])? 1 : 0;
        }
        int md = 1e9 + 3;
        ll ms = 0;
        int ans;
        for (int i=0; i<n-1; i++) {
            if (h[i+1] - h[i] <= md) {
                md = h[i+1] - h[i];
                ll s = (i > 0) ? hc[i-1] : 0;
                s+= hc.back() - hc[i+1];
                if (i > 0 && h[i+1] > h[i-1]) s++;
                if (i+2 < n && h[i] < h[i+2]) s++;
                if (s > ms) {
                    ans = i;  
                }
            } 
        }
        for (int i=ans; i<n; i++)
            if (i != ans+1)
                cout << h[i] << " ";
        for (int i=0; i<min(ans+2, n); i++)
            if (i != ans)
                cout << h[i] << " ";
        cout << endl;
    }
}
