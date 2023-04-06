#include <bits/stdc++.h>
using namespace std;


const int MAXN = 17;
const int MAXS = 32;

long long ways[MAXS][MAXN];

void mfill() {
    for (int i=0; i<MAXS; i++) {
        for (int j=0; j<MAXN; j++) {
            if (i == 0 || j == 0)
                ways[i][j] = 1;
            else {
                ways[i][j] = ways[i][j-1] + ways[i-1][j];
            }
        }
    }
}


int main() {
    int n;
    mfill();
    while (cin >> n) {
        if (n == 0) break;
        vector<int> ra(n);
        int s = 0;
        for (int i=0; i<n; i++) {
            int vi;
            cin >> vi;
            ra[i] = vi;
            s += vi;
        }
        long long res = 0;
        for (int i=0; i<s; i++) {
            res += ways[i][n-1];
        }

        for (int i=0; i<n; i++) {
            int vi = ra[i];
            int j = n - i - 2;
            if (j < 0) continue;
            vi--;
            while (vi >= 0) {
                res += ways[s - vi][j];
                vi--;
            }
            s -= ra[i];
        }
        res++;
        cout << res << endl;
    }
}
