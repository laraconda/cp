#include <bits/stdc++.h>
using namespace std;

const int MXN = (1e5 * 2) + 5;
bitset<MXN> bs;


int main () {
    int n;
    cin >> n;
    
    for (int i=0; i<n; i++) {
        int ni;
        cin >> ni;
        bs[ni] = 1;
    }
    
    for (int i=1; i<=n; i++)
        if (bs[i] == 0) cout << i << endl;
}
