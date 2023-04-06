#include <bits/stdc++.h>
using namespace std;


int main() {
    int T;
    cin >> T;

    for (int t=1; t<=T; t++) {
        int n;
        cin >> n;
        vector<char> as(n);
        vector<pair<pair<int, bool>, int>> ns;
        for (int i=0; i<n; i++) {
            int si, ei;
            cin >> si >> ei;
            ns.push_back({{si, 1}, i});
            ns.push_back({{ei, 0}, i});
        }

        sort(ns.begin(), ns.end());

        bool cfree = true;
        bool jfree = true;
        bool imp = false;
        for (int i=0; i<ns.size(); i++) {
            if (ns[i].first.second == 1) {
                if (cfree) {
                    as[ns[i].second] = 'C';
                    cfree = false;
                } else if (jfree) {
                    as[ns[i].second] = 'J';
                    jfree = false;
                } else {
                    imp = true;
                    break;
                }         
            } else {
                if (as[ns[i].second] == 'C') {
                    cfree = true; 
                } else if (as[ns[i].second] == 'J'){
                    jfree = true;
                }
            }
        }

        string res;
        if (imp) {
             res = "IMPOSSIBLE";
        } else {
            for (int i=0; i<n; i++) {
                res.push_back(as[i]);
            } 
        }

        as.clear();
        ns.clear();

        cout << "Case #" << t << ": " << res << endl;
    }
}
