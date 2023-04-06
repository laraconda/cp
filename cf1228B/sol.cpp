#include <bits/stdc++.h>
using namespace std;

const int MXN = 1e3 + 6;
const int M = 1e9+ 7;
int grid[MXN][MXN];

typedef long long ll;

void mfill() {
    for (int i=0; i<MXN; i++) {
        for (int j=0; j<MXN; j++) {
            grid[i][j] = -1;
        }
    }
}

ll bpow(ll a, ll b) {
    if (b == 0) return 1;
    if (b % 2) {
        return (a * bpow(a, b - 1)) % M;
    } else {
        ll res = bpow(a, b/2);
        return (res * res) % M;
    }
}

ll mcount(int h, int w) {
    ll c = 0;
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            if (grid[i][j] == -1) c++;
        }
    }
    return c;
}

int main() {
    int h, w;
    cin >> h >> w;
    mfill();
    
    ll n = h * w;
    for (int i=0; i<h; i++) {
        int ri;
        cin >> ri;
        for (int j=0; j<ri; j++) {
            grid[i][j] = 1; 
        }
        grid[i][ri] = 0; 
    }
    bool pos = true;
    for (int j=0; j<w; j++) {
        int ci;
        cin >> ci;
        for (int i=0; i<ci; i++) {
            if (grid[i][j] == -1)
                grid[i][j] = 1;
            else if (grid[i][j] != 1) pos = false;
        }
        if (grid[ci][j] == -1)
            grid[ci][j] = 0;
        else if (grid[ci][j] != 0) pos = false;
    }

    ll res = bpow(2, mcount(h, w));
    if (pos) cout << res << endl; else cout << 0 << endl;
}
