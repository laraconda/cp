#include <bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin >> t;
    while (t--) {
        int L, v, l, r;
        cin >> L >> v >> l >> r;

        int count = L / v;
        int next = l - (l % v) + v;
        if (l % v == 0)
            next = l;
        int prev = r - (r % v);
        int train = ceil((double)(prev - next + 1) / v);
        if (prev < l || next > r)
            train = 0;

        cout << count - train << endl;
    }
}
