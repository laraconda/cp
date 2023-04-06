#include <bits/stdc++.h>
using namespace std;

const int MXN = 1e5 +7;
vector<int> g[MXN];

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> es;
    for (int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        es.push_back({a, b});
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> cs(es.size(), -1);

    vector<pair<int, int>> fs;
    for (int i=1; i<=n; i++) {
        if (g[i].size() > 2) {
            for (int j=0; j<3; j++) {
                fs.push_back({i, g[i][j]});
                fs.push_back({g[i][j], i});
            }
            break; 
        }
    }

    int p = 0;
    if (fs.size()) {
        for (int i=0; i<fs.size(); i++) {
            for (int j=0; j<es.size(); j++){
                if (fs[i] == es[j]) {
                    cs[j] = p++;  
                }
            } 
        }
    }

    for (int i=0; i<cs.size(); i++) {
        if (cs[i] == -1) {
            cs[i] = p;
            p += 1;
            p %= n-1;
        }
    }
    for (int i=0; i<cs.size(); i++) {
        cout << cs[i] << endl;
    }
}
