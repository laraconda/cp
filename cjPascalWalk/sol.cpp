#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MXN = 50;
ll pasc[MXN][MXN];

void genpas() {
    pasc[0][0] = 1;
    for (int i=1; i<MXN; i++) {
        for (int j=0; j<=i; j++) {
            if (j == 0 || j == i) {
                pasc[i][j] = 1;
                continue;
            }
            pasc[i][j] = pasc[i-1][j] + pasc[i-1][j-1];
        }
    }
}

void lty(ll n) {
    for (int i=1; i<=n; i++) {
        cout << i << " " << i << endl;
    }
}

int gpos(ll n) {
    int last = 0;
    for (int i=0; i<33; i++) {
        if (n & 1) {
            last = i;
        }
        n >>= 1;
    }
    return last;
}

pair<int, int> shortw(ll n, ll& total) {
    cout << 1 << " " << 1 << endl;
    total++;
    int pos = gpos(n);
    n >>= 1;
    int r = 1;
    int k = 1;

    for (int i=1; i<=pos; i++) {
        r = i+1;
        if (n & 1) {
            if (k == 1) {
                for (int j=0; j<i+1; j++) {
                    k = j+1;
                    cout << r << " " << k << endl;
                    total += pasc[i][j];
                }
            } else {
                for (int j=i; j>=0; j--) {
                    k = j+1;
                    cout << r << " " << k << endl;
                    total += pasc[i][j];
                }
            }
        } else {
            total++;
            if (k != 1) k = r; 
            cout << r << " " << k << endl;
        }
        n >>=1;
    }
    return {r, k};
}

void walk(ll n) {
   ll total = 0;
   pair<int, int> pos = shortw(n-30, total); 
   int r = pos.first;
   int k = pos.second;
   if (k == 1) {
    for (int i=0; i<n-total; i++) {
        cout << (++r) << " " << k << endl;
    }
   } else {
       if (r != k) cout << "-------------r != k-----------" << endl;
    for (int i=0; i<n-total; i++) {
        cout << (++r) << " " << (++k) << endl;
    }
   }
}

int main() {
    int T;
    cin >> T;
    genpas();
    for (int t=1; t<=T; t++) {
       ll n;
       cin >> n;
       cout << "Case #" << t << ":" << endl;
       if (n <= 30) {
        lty(n); 
       } else {
        walk(n);
       }
    }
}
