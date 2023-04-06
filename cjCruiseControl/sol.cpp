#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool passes(double s, ll D, vector<pair<ll, ll>>& ns) {
    double hours = (double)D/s;
    double mind = D;
    for (int i=(int)ns.size() - 1; i>=0; i--) {
        double d = ns[i].first + hours * ns[i].second;
        if (d < mind) {
            mind = d;
        }
    }
    return (mind < D);
}

double bs(double l, double h, ll D, vector<pair<ll, ll>>& ns) {
    int times = 0;
    while (times < 111) {
        double mid = l + (h - l)/2;
        bool p = passes(mid, D, ns);
        if (p) {
            h = mid;
        } else {
            l = mid;
        }
        times++;
    }
    return l;
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

        double h = 1e9f;
        double res = bs(0, h, D, ns);

        cout.precision(20);
        cout << "Case #" << t << ": " << res << endl;
    }
}
