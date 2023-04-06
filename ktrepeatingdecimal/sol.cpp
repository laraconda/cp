#include <bits/stdc++.h>
using namespace std;

int main() {
    long double a;
    while (cin >> a) {
        long double b;
        cin >> b;
        int c;
        cin >> c;
        string res = "0.";

        while (c--) {
            if (a == 0) break;
            long double xi;
            a *= 10;
            for (long double i=0; i<10; i++) {
                if (a >= (b * i)) {
                    xi = i;
                }
            }
            a = (a - (b * xi));
            string sxi = to_string(xi);
            res.push_back(sxi[0]);
        }
        c++;
        while (c > 0) {
            c--;
            res.push_back('0');
        }
        cout << res << endl;
    }
}
