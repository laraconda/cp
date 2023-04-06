#include <bits/stdc++.h>
using namespace std;

const int MXN = 1e3 + 5;
vector<long long> css[MXN];

int main() {
    int n;
    cin >> n;

    vector<pair<long long, long long>> cs;
    for (int i=0; i<n; i++) {
        long long a, b;
        cin >> a >> b;
        cs.push_back({a, b});
    }

    int p;
    cin >> p;

    vector<long long> ps;
    while (p--) {
        long long pi;
        cin >> pi;
        ps.push_back(pi);
    }

    for (int i=0; i<n; i++) {
        auto ab = cs[i];
        long long a = ab.first;
        long long b = ab.second;
        for (long long& pi : ps) {
           if (a <= pi && pi <= b) {
            css[i].push_back(pi);
           } 
        }
    }
    
    vector<long long> newps;
    bool pos = true;
    for (int i=0; i<n; i++) {
        if (css[i].size() >= 3)
            pos = false;
        
        if (css[i].size() == 0) {
            long long newp = cs[i].first + (cs[i].second - cs[i].first)/2;
            newps.push_back(newp);
            css[i].push_back(newp);
        }
        if (css[i].size() == 1) {
            if (i < n - 1 && cs[i].second == cs[i+1].first && css[i+1].size() < 2 && css[i][0] != cs[i].second) {
                newps.push_back(cs[i].second);
                css[i].push_back(cs[i].second);
                css[i+1].push_back(cs[i].second);
            } else {
                long long newp;
                if (css[i][0] == cs[i].second || css[i][0] == cs[i].second - 1)
                    newp = css[i][0] - 1;
                else {
                    newp = css[i][0] + 1;
                }
                newps.push_back(newp);
                css[i].push_back(newp);
            }
        }
    }

    if (pos) {
        cout << newps.size() << endl;
        for (int i=0; i<(int)newps.size() - 1; i++) {
            cout << newps[i] << " "; 
        }
        if (newps.size() > 0) {
            cout << newps[(int)newps.size() - 1] << endl;
        }
    } else {
        cout << "impossible" << endl;
    }

}
