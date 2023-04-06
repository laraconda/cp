#include<bits/stdc++.h>
using namespace std;


const int MAXN = 3 * 1e5 + 2;

int a[2][MAXN];

int main() {
    int n, m;
    cin >> n >> m;

    int ai, bi;
    int xs[2];
    int ns[2] = {0, 0};
    for (int i=0; i<m; i++) {
        cin >> ai >> bi;

        if (i == 0) {
            xs[0] = ai;
            xs[1] = bi;
        }

        if (ai != xs[0] && bi != xs[0]) {
            ns[0] += 1;
            a[0][ai] += 1;
            a[0][bi] += 1;
        }
        
        if (ai != xs[1] && bi != xs[1]) {
            ns[1] += 1;
            a[1][ai] += 1;
            a[1][bi] += 1;
        }
    }

    bool pos = false;
    for (int i=0; i<2; i++) {
        for (int j=1; j<=n; j++) {
            if (ns[i] == a[i][j])
                pos = true; 
        }
    }

    if (pos)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

}
