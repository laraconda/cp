#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> ps;
        for (int i=0; i<n; i++) {
            int pi, ci;
            cin >> pi >> ci;
            ps.push_back({pi, ci});
        }
        
        bool pos = true;
        for (int i=0; i<n; i++) {
            if (ps[i].first < ps[i].second) {
               pos = false; 
            }
            if (i > 0) {
                if (ps[i].first < ps[i-1].first) {
                    pos = false;
                }
                if (ps[i].second < ps[i-1].second) {
                    pos = false;
                }
                int diffp = ps[i].first - ps[i-1].first;
                int diffc = ps[i].second - ps[i-1].second;
                if (diffc > diffp) pos = false;
            }
        }

        if (pos) cout << "YES"; else cout << "NO";
        cout << endl;
    }
}
