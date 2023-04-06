#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;
        int diff = y - x;
        int fstep;
        int gmm = 1e9;
        int fm = 0;
        for (int d=1; d<=diff; d++) {
            if (diff % d == 0 ) {
                int step = diff / d;
                int maxm = ceil((double)x/step) - 1;
                for (int m = 0; m <= maxm; m++) {
                    int mm = y + step * (n - m - 2);
                    if (gmm > mm && n - m - 2 >= 0 && n - m - 1 >= d) {
                        fstep = step;
                        gmm = mm;
                        fm = m;
                    }
                }
            }
        }
        int ai = x;
        while (fm >= 0) {
            cout << ai << " ";
            n--;
            fm--;
            ai -= fstep;
        }
        ai = x;
        while (n > 0) {
            ai += fstep;
            cout << ai << " ";
            n--;
        }
        cout << endl;
    }
}
