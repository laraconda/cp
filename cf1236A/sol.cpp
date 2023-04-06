#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;

        int stonesa = 0;

        int ops;
        ops = min(a, b/2);
        stonesa += ops * 3;
        ops = min (b - ops * 2, c/2);
        stonesa += ops * 3;


        int stonesb = 0;
        ops = min (b, c/2);
        stonesb += ops * 3;
        ops = min(a, (b - ops)/2);
        stonesb += ops * 3;

        int stones = max(stonesa, stonesb);
        cout << stones << endl;
    }
}
