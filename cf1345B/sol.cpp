#include <bits/stdc++.h>
using namespace std;

#define endl '\n';

typedef long long ll;
const ll MX = 1e9 + 2;
vector<ll> nc;

void prec() {
    nc.push_back(0);
    nc.push_back(2);
    for (int h=2; true; h++) {
        ll count = nc[h-1] + 2*h + h-1;
        nc.push_back(count);
        if (count > MX) break;
    }
}

int main() {
    int t;
    cin >> t;
    prec();
    while (t--) {
        int n;
        cin >> n;
        int np = 0;
        while (n > 1) {
            for (int h=0; h<nc.size(); h++) {
                if (nc[h] > n) {n-=nc[h-1]; np++; break;} 
            }
        }
        cout << np << endl;
    }
}
