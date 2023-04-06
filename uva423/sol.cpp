#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

const int MXN = 105;
int A[MXN][MXN];


void floyd(int n) {
    for (int k=0; k<n; k++)
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                A[i][j] = min(A[i][j], A[i][k] + A[k][j]);
}


int main() {
    int n;
    cin >> n;

    string aij;
    int val;
    for (int i=1; i<n; i++) {
        for (int j=0; j<i; j++) {
            cin >> aij;
            if (aij == "x")
                val = INF;
            else
                val = stoi(aij);
            A[i][j] = val;
            A[j][i] = val;
        }
    }
    
    floyd(n);
    int mx = 0;
    for (int i=0; i<n; i++) {
        mx = max(mx, A[0][i]);
    }

    cout << mx << endl;
}
