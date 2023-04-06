#include <bits/stdc++.h>
using namespace std;

const int MXN = 1e5 + 3;
int a[MXN];

int main() {
    int n, p;
    cin >> n >> p;

    int ai;
    for (int i=0; i<n; i++) {
        cin >> ai;
        a[i] = ai - p;
    }

    int maxsf = 0;
    int maxh = 0;
    for (int i=0; i<n; i++) {
        maxh += a[i];
        if (maxh < 0)
            maxh = 0;
        if (maxsf < maxh)
            maxsf = maxh;
    }

    cout << maxsf << endl;
}
