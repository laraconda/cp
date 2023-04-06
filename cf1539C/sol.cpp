#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll n, k, x;
    cin >> n >> k >> x;
    vector<ll> a(n);
    for (int i=0; i<(int)n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    priority_queue<ll, vector<ll>, greater<ll>> q;
    int c = 0;
    for (int i=0; i<(int)n-1; i++) {
        ll d = a[i+1] - a[i];
        if (d > x) {
            c++;
            q.push(d);
        }
    }
    while (!q.empty() && k >= 0) {
        ll d = q.top(); q.pop();
        ll z = ceil((long double)d/x) - 1;
        if (z <= k) c--;
        k -= z;
    }
    cout << c + 1 << endl;
}
