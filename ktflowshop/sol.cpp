#include <bits/stdc++.h>
using namespace std;


const int MXN = 1e3 + 6;
long long A[MXN][MXN];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
           int pij;
           cin >> pij;
           A[i][j] = pij;
        }
    }
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (i == 0 && j == 0)
                continue;
            if (i == 0)
                A[i][j] += A[i][j-1];
            else if (j == 0)
                A[i][j] += A[i-1][j];
            else {
                A[i][j] += max(A[i-1][j], A[i][j-1]);
            }
        }
    }

    for (int i=0; i<n-1; i++) {
        cout << A[i][m - 1] << " ";
    }
    cout << A[n-1][m - 1] << endl;
}
