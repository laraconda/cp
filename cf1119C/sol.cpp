#include <bits/stdc++.h>
using namespace std;

const int MXN = 507;
int A[MXN];
int B[MXN];


int main() {
    int n, m;
    cin >> n >> m;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            int ai;
            cin >> ai;
            A[i] = ai;
        }
    }
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            int bi;
            cin >> bi;
            B[i] = bi;
        }
    }
    
    int diffs = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (A[i] != B[i]) diffs++;
        }
    }

    if (diffs % 4 == 0 || diffs % 2)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

