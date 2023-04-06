#include <bits/stdc++.h>
using namespace std;


const int MAXN = 1002;
int f[MAXN][3];
int a[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i=n; i>0; i--)
        a[n - i + 1] = i;

    int ti, li, ri;
    for (int i=0; i<m; i++) {
        cin >> ti >> li >> ri;
        f[i][0] = ti;
        f[i][1] = li;
        f[i][2] = ri;
    }

    for (int i=0; i<m; i++) {
        for (int j=0; j<m; j++) {
            if (f[i][0] != 1 || f[j][0] != 1)
                continue;
            if (f[i][1] < f[j][1] &&
                f[i][2] > f[j][1] && f[i][2] < f[j][2]) {
                int low = f[i][1];
                int high = f[j][2];
                f[i][1] = low;
                f[j][1] = low;
                
                f[i][2] = high;
                f[j][2] = high;
            }
        }
    }

    bool pos = true;
    for (int i=0; i<m; i++) {
        for (int j=0; j<m; j++) {
            if (f[i][0] == 1 && f[j][0] == 0) {
                if (f[i][1] <= f[j][1] && f[j][2] <= f[i][2])
                    pos = false;
            }
        }
    }

    if (pos) {
        cout << "YES" << endl;
        for (int i=0; i<m; i++) {
            if (f[i][0] == 1) {
                if (a[f[i][1]] != n+1)
                    a[f[i][1]] = 1;
                for (int j=f[i][1] + 1; j<=f[i][2]; j++)
                    a[j] = n+1;
            }
        }

        for (int i=1; i<=n-1; i++) {
            cout << a[i] << " ";
        }
        cout << a[n] << endl;
    
    } else {
        cout << "NO" << endl;
    }
}
