#include <bits/stdc++.h>
using namespace std;

const int MXN = 1e3;
int a[MXN][MXN];

int main() {
    int r, c;
    cin >> r >> c;
    if (c > 1) {
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            a[i][j] = (i+1);
        }
    }
    for (int j=0; j<c; j++) {
        for (int i=0; i<r; i++) {
            a[i][j] *= (j+1+r);
        }
    }
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    } else if (c == 1 && r != 1) {
        for (int i=1; i<=r; i++) {
            cout << i+1 << endl;
        }
    
    } else {
        cout << 0 << endl;
    }


}
