#include <bits/stdc++.h>
using namespace std;


bool traverse(int ii, int jj, map<int, bool>& p) {
    int i = min(ii, jj);
    int j = max(ii, jj);
    bool pos = true;
    for (int z = i; z<j; z++) {
        if (p.count(z) <= 0) pos = false;    
    }
    return pos;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<pair<int,int>> a(n);
        for (int i=0; i<n; i++) {
            int ai;
            cin >> ai;
            a[i].first = ai;
            a[i].second = i;
        }

        map<int, bool> p;
        for (int i=0; i<m; i++) {
            int pi;
            cin >> pi;
            pi--;
            p[pi] = true;
        }
        sort(a.begin(), a.end());
        bool ans = true;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (a[j].second == i) {
                    if (!traverse(i, j, p)) ans = false;
                }
            }
        }
        string sans;
        if (ans) sans = "YES";
        else sans = "NO";
        cout << sans << endl;
    }
}
