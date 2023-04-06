#include <bits/stdc++.h>
using namespace std;


const int MXN = 102;
int ma[MXN][MXN];
int a[MXN];

int kadane(int n) {
    int msf = 0;
    int meh = 0;
    for (int i=1; i<=n; i++) {
        meh += a[i];
        if (meh < 0)
            meh = 0;

        if (meh > msf)
            msf = meh;
    }
    return msf;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    int maij;
    int ms = -200;
    cin >> n;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> maij;
            if (maij > ms)
                ms = maij;
            ma[i][j] = maij + ma[i][j-1];
        }
    }

    int res = 0;
    for (int j=1; j<=n; j++) {
        for (int jj=j; jj<=n; jj++) {
            for (int i=1; i<=n; i++) {
                a[i] = ma[i][jj] - ma[i][j-1];
            }
            int msf = kadane(n);
            if (msf > res)
                res = msf;
        }
    }

    if (res == 0)
        res = ms;

    cout << res << endl;
}
