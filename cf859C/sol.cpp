#include <bits/stdc++.h>
using namespace std;

const int msize = 50;
int slices[msize];
int totala[msize];
int dp[msize];

int total(int i, int n) {
    return totala[n-1] - totala[i];
}

int score(int i, int n) {
    if (i == n)
        return 0;
    if (dp[i] == 0)
        dp[i] = max(slices[i] + total(i, n) - score(i+1, n), score(i+1, n));
    return dp[i];
}

int main() {
    int n;
    cin >> n;

    for (int i=0; i<n; i++) {
        int si;
        cin >> si;
        slices[i] = si;
        totala[i] = si;
        if (i > 0)
            totala[i] += totala[i-1];
    }

    int bsum = score(0, n);
    int asum = totala[n-1] - bsum;

    cout << asum << " " << bsum << endl;
}
