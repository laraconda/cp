#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i=0; i<n; i++) {
            cin >> a[i];
        }
        ll su = 0;
        sort(a.begin(), a.end());
        for (int i=0; i<k; i++) {
            su += a[a.size()-1-i]; 
        }
        vector<int> w(k);
        for (int i=0; i<k; i++) {
            cin >> w[i];
        }
        sort(w.begin(), w.end());
        int j=n-k;
        int z=n-1;
        for (int i=0; i<k; i++) {
            if (w[i] - 1 > 0) {
                j -= w[i]-1;
                su += a[j];    
            } else {
               su += a[z];
               z--;
            }
        }
        
        cout << su << endl;
    }
}
