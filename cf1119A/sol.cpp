#include <bits/stdc++.h>
using namespace std;

const int MXN = 1e5*3 + 4;
int a[MXN];

int main() {
    int n;
    cin >> n;

    int first = -1;
    int ans = 0;
    for (int i=0; i<n; i++) {
        int ai;
        cin >> ai;
        a[i] = ai;
        if (first != -1 && ai != first)
            ans = i;
        if (i == 0)
            first = ai;
    }

    int last = -1;
    for (int i=n-1; i>=0; i--) {
        if (last != -1 && a[i] != last)
            ans = max(ans, n-1 - i);
        if (i == n-1)
            last = a[i];
    }

    cout << ans << endl;
}
