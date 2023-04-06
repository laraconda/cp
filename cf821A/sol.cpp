#include <bits/stdc++.h>
using namespace std;

const int MXN = 55;
int a[MXN][MXN];

int main() {
    int n;
    cin >> n;

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            int aij;
            cin >> aij;
            a[i][j] = aij;
        }
    }
    bool pos = true;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            int q = a[i][j];
            if (q == 1) continue;
            bool posaij = false;
            for (int ii=0; ii<n; ii++) {
                int b = a[ii][j];
                for (int jj=0; jj<n; jj++) {
                    int c = a[i][jj];
                    if (q == c + b) {
                        posaij = true;
                        break;
                    }
                }
                if (posaij) break;
            }
            if (!posaij)
                pos = false;
        }
    }
    if (pos)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
