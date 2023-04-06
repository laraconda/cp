#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;

    while (q--) {
        int n;
        cin >> n;

        int res;
        if (n % 2 == 0)
            res = 0;
        else
            res = 1;

        if (n <= 2)
            res = 4 - n;

        cout << res << endl;
    }
}
