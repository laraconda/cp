#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e10; 

vector<ll> pows;

void gpows() {
    ll a = 1;
    while (a < INF) {
        pows.push_back(a);
        a <<= 1;
    }
}

int main() {
    int t;
    cin >> t;
    gpows();
    while (t--) {
        int n;
        cin >> n;
        vector<ll> pas(n);
        for (int i=0; i<n; i++)
            cin >> pas[i];

        bool first = true;
        ll last;
        vector<ll> as;
        for (int i=0; i<n; i++) {
           if (first) {
               as.push_back(pas[i]);
               first = false;
           } else {
            if (pas[i] != last) as.push_back(pas[i]); 
           }
           last = pas[i];
        }

        n = as.size();
        vector<int> ts(pows.size() + 2);
        last = as[0];
        for (int i=1; i<n; i++) {
          if (as[i] < last) {
            ll diff = last - as[i];
            for (int j=0; j<pows.size(); j++) {
                if (ts[j]) continue;
                if (diff <= pows[j]) {
                    as[i] += pows[j];      
                    ts[j] = 1;
                    break;
                }
            }
          }
          last = as[i];
        }
        
        int T = 0;
        for (int i=0; i<ts.size(); i++) {
            if (ts[i]) T = i+1;
        }

        cout << T << endl;
    }
}
