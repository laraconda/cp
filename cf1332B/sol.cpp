#include <bits/stdc++.h>
using namespace std;


int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        vector<int> used(35);
        for (int i=0; i<35; i++) {
            used[i] = 0;
        }
        vector<int> cols(n);
        int c = 0;

        vector<int> ps = {2,3,5,7,11,13,17,19,23,29,31};
        
        for (int i=0; i<n; i++) {
            int ni;
            cin >> ni;

            for (int j=0; j<12; j++) {
                if (ni % ps[j] == 0) {
                    if (used[ps[j]] == 0) c++;
                    cols[i] = ps[j]; 
                    used[ps[j]]++;
                    break;
                }
            }
        }

        vector<int> us;
        for (int i=0; i<35; i++) {
            if (used[i] > 0) {
                us.push_back(i);
            }
        }

        sort(us.begin(), us.end());

        int cc = 0;
        int mmaps[35];
        for (int i=0; i<us.size(); i++) {
            mmaps[us[i]] = ++cc;
        }

        cout << c << endl;
        for (int i=0; i<n-1; i++) {
            cout << mmaps[cols[i]] << " ";
        }
        cout << mmaps[cols[n-1]] << endl;
    }
}
