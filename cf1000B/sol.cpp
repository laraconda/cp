#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n, M;
    cin >> n >> M;
    vector<int> a(n+2);
    a[0] = 0;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    a[n+1] = M;
    vector<ll> net(n+2);
    for (int i=n; i>=0; i--) {
        int s = (i % 2 != 0) ? -1 : 1;  
        net[i] += s * abs(a[i] - a[i + 1]);
        net[i] += net[i+1];
    }

    ll m = 1;
    for (int i=0; i<n+2; i++)
        m = min(m, net[i]);

    if (m < 0) {
        vector<int> ms;
        for (int i=0; i<n+2; i++)
            if (net[i] == m) ms.push_back(i);
        
        for (int i : ms) {
            if (i+1 < n + 2 && a[i] + 1 != a[i+1]) {
                a.insert(a.begin() + i+1, a[i]+1);
                break;
            }
            if (i-1 >= 0 && a[i] - 1 != a[i-1]) {
                a.insert(a.begin() + i, a[i] - 1);
                break;
            }
        }
    }
    ll res = 0;
    for (int i=1; i<a.size(); i++) {
        if (i % 2 != 0) {
            res += a[i] - a[i-1];
        }
    }
    cout << res << endl;
}
