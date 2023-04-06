#include <bits/stdc++.h>

using namespace std;


const int MXN = 1e4 + 4, M = 1e9 + 7;
int coes[MXN][MXN];

void bpascal() {
    coes[0][0] = 1;
    for (int n = 1; n < MXN; n++) {
        coes[n][0] = coes[n][n] = 1;
        for (int k = 1; k < n; k++)
            coes[n][k] = (coes[n - 1][k - 1] + coes[n - 1][k]) % M;
    }
}

int main() {
    bpascal();

    int q;
    cin >> q;

    while (q--) {
        int n, m;
        cin >> n >> m;
        cout << coes[n][m] << endl;
    }
}
