#include <bits/stdc++.h>
using namespace std;

const int MXN = 2003;

int a[MXN];
int n;

int M(int i, int x, int y) {
    if (i == n)
        return 0;
    if (x == -1)
        return max(M(i+1, -1, -1), M(i+1, a[i], a[i]) + 1);
    if (a[i] < x) {
        return max(M(i+1, a[i], y) + 1, M(i+1, x, y));
    } else if (a[i] > y) {
        return max(M(i+1, x, a[i]) + 1, M(i+1, x, y));
    } else
        return M(i+1, x, y);
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin >> n;

    int ai;
    for (int i=0; i<n; i++) {
        cin >> ai;
        a[i] = ai;
    }

    cout << M(0, -1, -1) << endl;
}
