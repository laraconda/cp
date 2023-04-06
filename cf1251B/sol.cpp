#include <bits/stdc++.h>
using namespace std;


int main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;


        int PP = 0;
        int PI = 0;
        int II = 0;
        for (int i=0; i<n; i++) {
            string si;
            cin >> si;
            int z = 0;
            int o = 0;
            for (int i=0; i<(int)si.size(); i++) {
                if (si[i] == '0') {
                    z++;
                } else {
                    o++;
                }
            }
            if (z % 2 == 0 && o % 2 == 0)
                PP++;
            else if (z % 2 == 0 || o % 2 == 0)
                PI++;
            else
                II++;
        }

        int res = PP;
        res += (II/2) * 2;
        if (II & 1 && PI > 0)
            res++;
        
        res += PI;
        
        cout << res << endl;
    }
}
