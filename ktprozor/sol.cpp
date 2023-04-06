#include <bits/stdc++.h>
using namespace std;

const int MXN = 105;
int a[MXN][MXN];
int b[MXN][MXN];
int c[MXN];
int cc[MXN];
char draw[MXN][MXN];

int main() {
    int r, s, k;
    cin >> r >> s >> k;

    char aij;
    for (int i=1; i<=r; i++) {
        for (int j=1; j<=s; j++) {
            cin >> aij;
            draw[i][j] = aij;
            if (aij == '*' && i != 1 && i != r && j != 0 && j != s)
                a[i][j] = 1;
        }
    }

    int su;
    for (int i=1; i<=r; i++) {
        su = 0;
        for (int j=1; j<=s; j++) {
            su += a[i][j];
            b[i][j] = su;
        }
    }

    k -= 2;
    int fi;
    int fj;
    int score = 0;
    int mxs = 0;
    for (int i=s-1; i-k>0; i--) {
        for (int j=2; j<r; j++) {
            c[j] = b[j][i] - b[j][i-k];
        }
        
        cc[2] = c[2];
        for (int ii=3; ii<r; ii++) {
            cc[ii] = cc[ii-1] + c[ii];
        }

        for (int j=r-1; j-k>0; j--) {
            score = cc[j] - cc[j-k];
            if (score > mxs) {
                mxs = score;
                fi = j+1;
                fj = i+1;
            }
        }
    }
    k +=1;

    cout << mxs << endl;
    for (int i=1; i<=r; i++) {
        for (int j=1; j<=s; j++) {
            if ((i == fi - k && j == fj - k) || (i == fi - k && j == fj)
                || (i == fi && j == fj - k) || (i == fi && j == fj)) {
                cout << '+';
            } else if ((j == fj || j == fj - k) && i >= fi - k && i <= fi)
                cout << '|';
            else if ((i == fi || i == fi - k) && j >= fj - k && j <= fj)
                cout << '-';
            else
                cout << draw[i][j];
        }
        cout << endl;
    }
}
