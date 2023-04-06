#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;

    while (q--) {
        int ni;
        cin >> ni;

        int rem = ni%4;
        int res = -1;

        if (rem == 0) {
            res = ni/4;
        } else if (rem == 1) {
            if (ni - 9 > -1 && (ni-9)%4 == 0) {
                res = (ni-9)/4 + 1;
            }
        } else if (rem == 2) {
            if (ni - 6 > -1 && (ni-6)%4 == 0) {
                res = (ni-6)/4 + 1;
            }
        } else if (rem == 3) {
            if (ni - 15 > -1 && (ni-15)%4 == 0) {
                res = (ni-15)/4 + 2;
            }
        }

        cout << res << endl;
    }
}
