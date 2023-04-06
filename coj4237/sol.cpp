#include <bits/stdc++.h>
using namespace std;

const int MXN = 1e6 + 3;
long long asu[MXN];
int b[MXN];

int main() {
    int n;
    cin >> n;

    vector<int> a;
    int ai;
    a.push_back(0);
    for (int i=1; i<=n; i++) {
        cin >> ai;
        a.push_back(ai);
    }

    for (int i=1; i<= n; i++) {
        asu[i] = a[i] + asu[i-1];
    }

    long long su = 0;
    for (int i=1; i<=n; i++) {
        su += (asu[n] - asu[i]) - (long long)a[i]*(n-i);
    }

    reverse(a.begin(), a.end());
    for (int x : a) {
        if (x == 0)
            continue;
        b[x]++;
        su -= b[x+1];
        su += b[x-1];
    }

    cout << su << endl;
}
