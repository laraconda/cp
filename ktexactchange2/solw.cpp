#include <bits/stdc++.h>
using namespace std;

const int MXN = (1e4 + 2) * 2;
int a[MXN];
map<int, int> b[MXN];

void clearab() {
    for (int i=0; i<MXN; i++) {
        a[i] = MXN;
        b[i].clear();
    }
    
}

int main() {
    int t;
    cin >> t;

    vector<int> cs;
    map<int, int> totalc;

    while(t--) {
        int n, m;
        cin >> n >> m;

        clearab();
        int ci;
        for (int i=0; i<m; i++) {
            cin >> ci;
            cs.push_back(ci);
            totalc[ci]++;
        }

        vector<int> mmds;
        for (pair<int, int> tc : totalc)
            mmds.push_back(tc.first);
        
        reverse(mmds.begin(), mmds.end());

        a[0] = 0;
        for (int c : mmds) {
            for(int j=c; j<MXN; j++) {
                if (b[j-c][c] >= totalc[c])
                    continue;
                if (a[j] > a[j-c] + 1) {
                    a[j] = a[j-c] + 1;
                    for (pair<int, int> e : b[j-c])
                        b[j][e.first] = e.second;
                    b[j][c]++;
                }
            }
        }

        int am;
        int coins;
        for (int i=n; i<MXN; i++) {
            if (a[i] != MXN) {
                am = i;
                coins = a[i];
                break;
            }
        }

        cout << am << " " << coins << endl;
        
        cs.clear();
        totalc.clear();
    }
}
