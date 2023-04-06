#include <bits/stdc++.h>
using namespace std;

const int MXN = 2005;
int dp[MXN][MXN];


int rec(int i, int t, int l, int r,
bool slept, vector<int>& as, int h, int n) {

    t %= h;
    int plus = 0;
    if (slept && l <= t && t <= r) plus++;
    if (i == n) return plus;
    if (dp[i][t] != -1) return dp[i][t];
    int a = rec(i+1, t + as[i], l, r, true, as, h, n);
    int b = rec(i+1, t + as[i] - 1, l, r, true, as, h, n);
    return dp[i][t] = (max(a, b) + plus);
}

int main() {
    int n, h, l, r;
    cin >> n >> h >> l >> r;

    vector<int> as(n);
    for (int i=0; i<n; i++) {
        int ai;
        cin >> ai;
        as[i] = ai;
    }

    for (int i=0; i<MXN; i++) {
        for (int j=0; j<MXN; j++) {
            dp[i][j] = -1;
        }
    }

    int res = rec(0, 0, l, r, false, as, h, n);

    cout << res << endl;
}
