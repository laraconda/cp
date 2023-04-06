#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

double slowest(ll D, vector<pair<ll, ll>>& ns) {
    double lt = 0;
    for (int i=(int)ns.size() - 1; i>=0; i--) {
        double d = D - ns[i].first;
        double ti = d/ns[i].second;
        if (ti > lt) {
            lt = ti;
        }
    }
    return lt;
}

int main() {
    int T;
    cin >> T;

    for (int t=1; t<=T; t++) {
        ll D, N;
        cin >> D >> N;
        vector<pair<ll, ll>> ns(N);
        for (int i=0; i<N; i++) {
            ll ki, si;
            cin >> ki >> si;
            ns[i] = {ki, si};
        }
        
        sort(ns.begin(), ns.end());
        double lt = slowest(D, ns);
        double res = (double)D/lt;

        cout.precision(10);
        cout << "Case #" << t << ": " << res << endl;
    }
}
