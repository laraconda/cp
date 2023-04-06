#include <bits/stdc++.h>
using namespace std;

const int MXN = 3e3;
int A[MXN][MXN];
int B[MXN][MXN];
bitset<MXN> vis;

int main() {
    int n;
    cin >> n;
   
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            int aij;
            cin >> aij;
            A[i][j] = aij;
        }
    }

    cout << mnew << endl;
}
