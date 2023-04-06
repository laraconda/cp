#include <bits/stdc++.h>
using namespace std;

bool msort(pair<pair<int, bool>, int> a, pair<pair<int, bool>, int> b) {
    if (a.first.first < b.first.first)
        return true;
    else if (a.first.first == b.first.first) {
        if (a.first.second == false)
            return true;
        if (b.first.second == false)
            return false;
        return true;
    } else 
        return false;
}

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
            ns.push_back({{si, true}, i});
            ns.push_back({{ei, false}, i});
        }

        sort(ns.begin(), ns.end(), msort);

        bool cfree = true;
        bool jfree = true;
        bool imp = false;
        for (int i=0; i<ns.size(); i++) {
            if (ns[i].first.second) {
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

        cout << "Case #" << t << ": " << res << endl;
    }

}
