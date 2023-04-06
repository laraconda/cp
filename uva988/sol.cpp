#include <bits/stdc++.h>
using namespace std;

const int MXN = 1e7;
vector<int> g[MXN];
int ops[MXN];


void mclear(int n) {
    for (int i=0; i<=n; i++) {
        ops[i] = 0;
        g[i].clear();
    }
}

int main() {
    int k = 0;
    int n;
    bool first = true;
    while (cin >> n) {
        if (first)
            first = false;
        else
            cout << endl;

        int m;
        for (int i=0; i<n; i++) {
            cin >> m;
            int ai;
            while (m--) {
                cin >> ai;
                g[i].push_back(ai);
            } 
        }
        
        int ans = 0;
        ops[0] = 1;
        for (int i=0; i<n; i++) {
            if (g[i].empty()) ans += ops[i];
            for (int ne : g[i]) {
                ops[ne] += ops[i];
            }   
        }

        cout << ans << endl;
        mclear(n);
    }
}
