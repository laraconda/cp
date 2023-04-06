#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int t, c;
    cin >> t >> c;

    int a, b;
    cin >> a >> b;

    int res;
    if (b > a)
        res = ((b - a - 1) * (t + 2*c)) + 2*c;
    else {
        res = (a - b + 1) * (t + 2*c) - 2*c;
    }
        
    cout << res << endl;
}
