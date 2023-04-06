/* Suppose there's two monks, one going up and one 
 * going down and they both start at the same time.
 * Binary search the point in which the monks cross.
 * Its easy to determine how much distance a monk has
 * traveled given the time  in O(max(a, d).
 * If dist(a) >= D - dist(b) then they have
 * already crossed. D is the total distance.
 */


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<pair<ll, ll>> as;
vector<pair<ll, ll>> ds;

double passed(double ti, ll D) {
    ll tt = 0;
    ll th = 0;
    double pa;
    for (int i=0; i<as.size(); i++) {
        tt += as[i].second;
        th += as[i].first;
        if (ti < tt) {
            pa = th - as[i].first;
            pa += (ti - (tt - as[i].second)) * ((double)as[i].first/as[i].second);
            break;
        }
        if (ti == tt) {
            pa = th;
            break;
        }
    }

    tt = 0;
    th = 0;
    double pd;
    for (int i=0; i<ds.size(); i++) {
        tt += ds[i].second;
        th += ds[i].first;
        if (ti < tt) {
            pd = th - ds[i].first;
            pd += (ti - (tt - ds[i].second)) * ((double)ds[i].first/ds[i].second);
            break;
        }
        if (ti == tt) {
            pd = th;
            break;
        }
    }
    return (D - pd <= pa);
}


double bs(double l, double h, ll D) {
    for (int z=0; z<111; z++) {
        double mid = l + (h - l)/2;
        if (passed(mid, D)) {
            h = mid;
        } else {
            l = mid;
        }
    }
    return h;
}

int main() {
    int a, d;
    cin >> a >> d;

    ll totta = 0;
    ll D = 0;
    for (int i=0; i<a; i++) {
        ll h, t;
        cin >> h >> t;
        totta += t;
        D += h;
        as.push_back({h, t});
    }
    
    ll tottd = 0;
    for (int i=0; i<d; i++) {
        ll h, t;
        cin >> h >> t;
        tottd += t;
        ds.push_back({h, t});
    }

    double ti = bs(0, min(tottd, totta), D);
    cout << fixed << setprecision(9) << ti << endl;
}
