#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;

    vector<int> mmins;
    vector<int> mmaxs;
    ll as = 0;
    ll nas = 0;
    for (int i=0; i<n; i++) {
        int li;
        cin >> li;
        bool isas = false;
        int first = -1;
        int last;
        for (int j=0; j<li; j++) {
            int si;
            cin >> si;
            if (first == -1) {
                first = si; 
            } else {
                if (last < si) {
                    isas = true; 
                }
            }
            last = si;
        }
        if (isas) {
            as++;
        } else {
            nas++;
            mmaxs.push_back(first);
            mmins.push_back(last);
        }
    }

    ll res = as * as + (as * nas) * 2ll;

    sort(mmins.begin(), mmins.end());
    for (int m : mmaxs) {
        res += distance(mmins.begin(), lower_bound(mmins.begin(), mmins.end(), m));
    }
    cout << res << endl;
}
