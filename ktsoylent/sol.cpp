#include <bits/stdc++.h>
using namespace std;

int main () {
    int t;
    cin >> t;

    int n;
    int res;
    while (t--) {
        cin >> n;
        res = ceil((double)n/400);
        cout << res << endl;
    }
}
