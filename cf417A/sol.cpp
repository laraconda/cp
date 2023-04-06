#include <bits/stdc++.h>
using namespace std;

int main() {
    int c, d;
    cin >> c >> d;
    int n, m;
    cin >> n >> m;
    int k;
    cin >> k;

    int t = n * m - k;
    if (t < 0) t = 0;

    double x = (double)n / c;
    double y = (double)1/d;

    int tp = 0;
    int res;
    if (x > y) {
    while (t >= n) {
        t-=n;
        tp += c;
    }
    if (t <= 0)
        res = tp;
    else 
        res = min(tp + c, tp + d*t);
    } else {
        res = t*d;
    }

    cout << res << endl;
}
