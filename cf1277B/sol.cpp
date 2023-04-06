#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MXN = 1e9 + 3;

vector<ll> pows;

void gen() {
   ll p = 1;
   while (p < MXN) {
    pows.push_back(p);
    p *= 2;
   } 
}

ll godd(ll ai, int& ex) {
    for (int i=pows.size()-1; i>=0; i--) {
        if (ai % pows[i] == 0) {
            ex = i;
            return ai/pows[i];
        }
    }
}

int main() {
    int t;
    cin >> t;
    gen();
    while (t--) {
        int n;
        cin >> n;

        map<ll, int> m;
        
        for (int i=0; i<n; i++) {
            ll ai;
            cin >> ai;
            int ex;
            ll odd = godd(ai, ex);

            if (m.count(odd)) {
                m[odd] = max(m[odd], ex);    
            } else {
                m[odd] = ex;
            }
        }

        ll res = 0;
        for (auto n_e : m) {
            res += n_e.second;
        }

        cout << res << endl;
    }
}
