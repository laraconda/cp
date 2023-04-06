#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        set<int> s;
        int ma = -1;
        for (int i=0; i<n; i++) {
            int ai;
            cin >> ai;
            s.insert(ai);
            ma = max(ma, ai);
        }
        bool h = false;
        int me = ma + 1;
        for (int i=0; i<ma; i++) {
            if (s.count(i) == 0) {
                h = true;
                me = i;
                break;
            }
        }
        int c = s.size();
        if (h) {
            int ne = ceil((double)(ma + me)/2);
            if (k > 0 && s.count(ne) == 0) {
                c++;
            }
        } else c += k;
        cout << c << endl;

    }
}
