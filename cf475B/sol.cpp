#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MXN = 405;
const ll INF = 1e12;
ll D[MXN][MXN];

void floyd(int n) {
    for (int k=0; k<n; k++) {
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
    }
}

int main() {
   int n, m;
   cin >> n >> m;
   string a,b;
   cin >> a >> b;

   for (int i=0; i<MXN; i++) {
    for (int j=0; j<MXN; j++) {
        if (i == j) continue;
        D[i][j] = INF;
    }
   }

   for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
        int x = i*m + j;
        char dirb = b[j];
        if (dirb == '^') {
            int y = (i-1)*m + j;
            if (i > 0) {
                D[x][y] = 1;
            }
        } else {
            int y = (i+1)*m + j;
            if (i < n-1) {
                D[x][y] = 1;
            }
        }
        if (a[i] == '<') {
            int y = i*m + j - 1;
            if (j > 0) {
                D[x][y] = 1;
            }
        } else {
            int y = i*m + j + 1;
            if (j < m-1) {
                D[x][y] = 1;
            }
        }
    }
   }
   floyd(n*m);

   bool pos = true;
   for (int i=0; i<n*m; i++) {
    for (int j=0; j<n*m; j++) {
        if (D[i][j] == INF) pos = false;
    }
   }

   if (pos) cout << "YES" << endl;
   else cout << "NO" << endl;
}
