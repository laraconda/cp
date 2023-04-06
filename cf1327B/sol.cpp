#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> bfs(n+2);
        vector<int> gfs(n+2);
        for (int i=1; i<=n; i++) {
            int k;
            cin >> k;

            for (int j=0; j<k; j++) {
                int bi;
                cin >> bi;
                if (gfs[i] == 0 && bfs[bi] == 0) {
                    bfs[bi] = 1;                
                    gfs[i] = 1;
                }
            }
        }
       
        int lg = -1;
        for (int i=1; i<=n; i++) {
            if (gfs[i] == 0) {
                lg = i;
            }
        }
        int lb = -1;
        for (int i=1; i<=n; i++) {
            if (bfs[i] == 0) {
                lb = i;
            }
        }

        if (lg == -1) {
            cout << "OPTIMAL" << endl;
        } else {
            cout << "IMPROVE" << endl;
            cout << lg << " " << lb << endl;
        }
    }
}
