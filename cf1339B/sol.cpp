#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<ll> as(n);
        for (int i=0; i<n; i++) 
            cin >> as[i];
        sort(as.begin(), as.end());

        vector<ll> res;
        int plus = n-1;
        int s = -1;
        int curr = n-1;
        while (plus > 0) {
            res.push_back(as[curr]);
            curr += plus * s;
            s = (s == 1) ? -1 : 1; 
            plus--;
        }
        res.push_back(as[curr]);

        reverse(res.begin(), res.end());

        for (auto x : res)
            cout << x << " ";
        cout << endl;
    }

}
