#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        priority_queue<ll> evens;
        priority_queue<ll> odds;
        for (int i=0; i<n; i++) {
            ll ai;
            cin >> ai;
            if (ai % 2== 0) {
                evens.push(ai);
            } else {
                odds.push(ai);
            }
        }
        int i = 0;
        ll A = 0;
        ll B = 0;
        while (true) {
            ll e =-1;
            if (!evens.empty()) e = evens.top();
            ll o = -1;
            if (!odds.empty()) o = odds.top();
            if (e == -1 && o == -1) {
                break;
            }
            if (i == 0) {
                if (e > o) {
                    A += e;    
                    evens.pop();
                } else odds.pop();
                i = 1;
            } else {
                if (o > e) {
                    B+= o;
                    odds.pop();
                } else evens.pop();
                i = 0;
            }
        }
        if (A > B) {
            cout << "Alice" << endl;
        } else if (B > A) cout << "Bob" << endl;
        else cout << "Tie" << endl;
    }
}
