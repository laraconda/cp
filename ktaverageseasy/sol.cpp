#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int nc, ec;
        cin >> nc >> ec;

        long long avcsum = 0;
        double avc = 0;
        vector<int> comps;
        for (int i=0; i<nc; i++) {
            int ci;
            cin >> ci;
            comps.push_back(ci);
            avcsum += ci;
        }
        avc = (double)avcsum / nc;
        
        long long avesum = 0;
        for (int i=0; i<ec; i++) {
            int ei;
            cin >> ei;
            avesum += ei;
        }
        double ave = (double)avesum / ec;
        
        int res = 0;
        for (int ci : comps) {
            avcsum -= ci; 
            double newavc = (double)avcsum / (nc - 1);
            avesum += ci;
            double newave = (double)avesum / (ec + 1);
            if (newavc > avc && newave > ave) {
                res++; 
            }

            avcsum += ci;
            avesum -= ci;
        }
        cout << res << endl;
    }
}
