#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MAXA = 1e16;

int main() {
    int t;
    cin >> t;
    while (t--) {
       ll n, k;
       cin >> n >> k;

       vector<ll> ns(n);
       for (int i=0; i<n; i++) {
        cin >> ns[i];
       }

       int s = 0;
       ll p = 1;
       vector<ll> ps;
       ps.push_back(1);
       do {
        p *= k;
        if (p > MAXA) break;
        s++;
        ps.push_back(p);
       } while(p <= MAXA);

       bool pos = true;
       while (s >= 0) {
           ll p = ps[s];
           int c = 0;
           int j;
            for (int i=0; i<n; i++) {
                if (ns[i] >= p) {
                    c++;
                    j = i;
                }
            }
            if (c == 1) {
               ns[j] -= p;
            } else if (c > 1) {
                pos = false; 
                break;
            }
            s--;
            if (!pos) break;
       }

       for (int i=0; i<n; i++) {
        if (ns[i] != 0) {
            pos = false;
        }
       }

       if (pos) cout << "YES"; else cout << "NO";
       cout << endl;
    }
}
