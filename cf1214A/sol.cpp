#include <bits/stdc++.h>
using namespace std;


int main() {
    long long n, d, e, res;
    cin >> n >> d >> e;
    e *= 5;
    res = n;
    for (int i=0; i<n; i++) {
        if (n - i * e < 0) break;
        res = min(res, (n - i * e) % d); 
    }

    cout << res << endl;
}
