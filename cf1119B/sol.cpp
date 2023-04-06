#include<bits/stdc++.h>
using namespace std;

const int MXN = 1e3 + 5;
long long a[MXN];
multiset<long long> ms;

int main() {
    int n, h;
    cin >> n >> h;
    for (int i=0; i<n; i++) {
        long long ai;
        cin >> ai;
        a[i] = ai;
    }

    int ans = 0;
    bool pos = true;
    for (int i=0; i<n; i++) {
        ms.insert(a[i]);
        int lim = h;
        int total = 0;
        auto x = ms.end();
        bool out = false;
        while (!out) {
            x--;
            int a = -1;
            if (x != ms.begin()) {
                a = *x; total++;
            } else {
                a = *x; total++;
                break;
            }
            int b = -1;
            if ((--x) == ms.begin()) {
                b = *x; total++;
            } else {
                b = *x; total++;
                out = true;
            }
            int m = max(a, b);
            if (m == -1) break;
            if (m <= lim) {
                lim -= m;
            }
        }
        if (total != i+1) pos = false;
        if (pos) ans = i+1;
    }
    cout << ans << endl;
}
