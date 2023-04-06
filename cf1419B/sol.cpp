#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> s;
vector<ll> ags;

void ps() {
    ll n = 1;
    for (int i=0; i<100; i++) {
        s.push_back(n);
        n = n*2 + 1;
    }
}

ll gauss(ll n) {return n*(n+1)/2;}

void cags() {
    for (ll a : s) {
        ll g = gauss(a);
        ll prev = 0;
        if (!ags.empty())
            prev = ags.back();
        ags.push_back(g + prev);
    }
}


int main() {
    ps();
    cags();
    int t;
    cin >> t;
    while (t--) {
        ll x;
        cin >> x;
        for (int i=0; i<ags.size(); i++) {
            if (ags[i] > x) {
                cout << i << endl;
                break;
            }
        }
    }
}
