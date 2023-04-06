#include <bits/stdc++.h>
using namespace std;

const int MXN = 2003;

int a[MXN];
int b[MXN];
int c[MXN];


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n; 
    cin >> n;

    int ai;
    for (int i=0; i<n; i++) {
        cin >> ai;
        a[i] = ai;
        b[i] = 1;
        c[i] = 1;
    }

    int res = 1;
    for (int i=n-1; i>=0; i--) {
        for (int j=n-1; j>i; j--) {
            if (a[j] > a[i])
                b[i] = max(b[i], b[j] + 1);
            else
                c[i] = max(c[i], c[j] + 1); 
            res = max(res, c[i] + b[i] - 1);
        }
    }
    
    if (n == 0)
        res = 0;    
    cout << res << endl;
}
