#include <bits/stdc++.h>
using namespace std;

const int MXN = 152;
double dp[MXN][MXN];

vector<pair<int, double>> cs;


void mfill() {
    for (int i=0; i<MXN; i++) {
        for (int j=0; j<MXN; j++) {
            dp[i][j] = -1;
        }
    }
    cs.clear();
}


double C(int i, double p, int v, int n) {
    if (dp[v][i] != -1) return dp[v][i];
    if (v <= 75) return -1;
    if (i == n)
        return 1;
    else
        return dp[v][i] = max(C(i + 1, p, v - cs[i].first, n), C(i + 1, p, v, n) * cs[i].second); 
}


int main () {
    int t;
    cin >> t;
    while (t--) {
        mfill();
        int n;
        cin >> n;
        for (int i=0; i<n; i++) {
            int vi, pi;
            cin >> vi >> pi;
            cs.push_back({vi, (double)pi/100});
        }
        double res = C(0, 1, 150, n);
        printf("%.10f\n", res*100);
    }

}
