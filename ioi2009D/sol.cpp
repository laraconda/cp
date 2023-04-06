/*
 * Dynamic programming solution. Recursve.
 * Notice that the min value for a square with points (i1,j1)
 * and (i2, j2) (inclusive) is the total sum of 1x1 squares
 * contained in it plus the min value of splitting it.
 * Splitting is cutting up the original square into two squares
 * (a and b) that togheter form the original.
 * There are many ways to split it.
 * We can split it by the end of the first row or second row...
 * by the end of the n-2 row. The same with columns.
 * All of those splits are going to have a value, that is the
 * minimum value of completely dismembering square 'a' plus
 * the minimum value of dismembering square 'b'.
 * Among those splits, at we are going to pick the one with the
 * smallest value.
 */



#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;  // Infinite val
const int MXN = 55;
int g[MXN][MXN];  // grid
ll su[MXN][MXN];  // cummulative sum to make fast queries

ll dp[MXN][MXN][MXN][MXN];


/* returns the sum of the square defined by (i1, j1) and (i2, j2)
 * inclusive. In constant time.
 */
ll qsu(int i1, int i2, int j1, int j2) {
    ll res = su[i2][j2];
    if (j1-1 >= 0)
        res -= su[i2][j1-1];
    if (i1-1 >= 0)
        res -= su[i1-1][j2];
    if (i1 - 1 >= 0 && j1-1 >= 0)
        res += su[i1-1][j1-1];
    return res;
}

/* returns the min possible value after cutting up the square
 * defined by (i1,j1) and (i2, j2)
 */
ll fdp(int i1, int i2, int j1, int j2) {
    // 1x1 suquare, nothing to do and nothing to add
    if (i1 == i2 && j1 == j2) return 0;
    if (dp[i1][i2][j1][j2] != 0) return dp[i1][i2][j1][j2];
   
    // getting the value of the full square
    // i.e the sum of all its 1x1 squares
    ll res = qsu(i1, i2, j1, j2);
   
    ll minval = INF;
    
    // splitting the square by rows
    for (int i=i1; i<i2; i++) {
        ll diva = fdp(i1, i, j1, j2);
        ll divb = fdp(i+1, i2, j1, j2);
        minval = min(minval, diva + divb);
    }

    // splitting the square by columns
    for (int j=j1; j<j2; j++) {
        ll diva = fdp(i1, i2, j1, j);
        ll divb = fdp(i1, i2, j+1, j2);
        minval = min(minval, diva + divb); 
    
    }
    res += minval; // adding value of the min split
    return dp[i1][i2][j1][j2] = res;
}


// filling array su to make fast queries
void fillsu(int n, int m) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            su[i][j] = g[i][j];
            if (i - 1 >= 0)
                su[i][j] += su[i-1][j];
            if (j - 1 >= 0)
                su[i][j] += su[i][j-1];
            if (j - 1 >=0 && i - 1 >= 0) {
                su[i][j] -= su[i-1][j-1];
            }
        }
    }
}


int main() {
    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> g[i][j];
        }
    }

    fillsu(n, m);
    
    ll res = fdp(0, n-1, 0, m-1);
    cout << res << endl;
}
