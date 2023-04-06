#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<int, int> m;
        for (int i=0; i<n; i++) {
            ll ai;
            cin >> ai;
            int last = -1;
            for (int j=0; j<32; j++) {
                if (ai & 1) {
                    last = j;
                }
                ai = ai >> 1;
            }
            m[last]++;
        }

        ll res = 0;
        for (auto x_c : m) {
            res += ((ll)x_c.second * (x_c.second - 1))/2;
        }
        cout << res << endl;
    }
}
