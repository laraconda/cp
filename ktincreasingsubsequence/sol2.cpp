#include <bits/stdc++.h>
using namespace std;

const int MXN = 1e5+3;
long long a[MXN];
typedef long long ll;


deque<ll> lis(int n) {
    vector<ll> b(n, LLONG_MAX);
    deque<ll> ans;
    map<pair<ll, ll>, pair<ll, ll>> pth;
    int sz = 0;
    for (int i=0; i<n; i++) {
        auto it = upper_bound(b.begin(), b.end(), a[i]-1);
        if (*it == LLONG_MAX) sz++;
        *it = min(a[i], *it);
        int pos = distance(b.begin(), it);
        pth[make_pair(pos, a[i])] = {pos - 1, b[pos-1]};
    }
    pair<ll, ll> cu = {sz - 1, b[sz - 1]};
    do {
        ans.push_front(cu.second);
        cu = pth[cu];
    } while(--sz);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    int ai;
    cin >> n;
    while(n != 0) {
        for (int i=0; i<n; i++) {
            cin >> ai;
            a[i] = ai;
        }
        deque<ll> dq = lis(n);
        cout << dq.size() << " ";

        for (int i=0; i<dq.size()-1; i++)
            cout << dq[i] << " ";
        cout << dq[dq.size()-1] << endl;
        
        cin >> n;
    }
}

