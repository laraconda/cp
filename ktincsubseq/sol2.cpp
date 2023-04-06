#include <bits/stdc++.h>
using namespace std;

const int MXN = 1e5+3;
long long a[MXN];


deque<long long> lis(int n) {
    vector<long long> b(n, LLONG_MAX);
    deque<long long> ans;
    map<pair<long long, long long>, pair<long long, long long>> pth;
    int sz = 0;
    b[0] = LLONG_MIN;
    for (int i=0; i<n; i++) {
        auto it = upper_bound(b.begin(), b.end(), a[i]-1);
        if (*it == LLONG_MAX)
            sz++;
        *it = min(a[i], *it);
        int pos = distance(b.begin(), it);
        pth[make_pair(pos, a[i])] = make_pair(pos - 1, b[pos-1]);
    }
    pair<long, long> cu = make_pair(sz, b[sz]);
    do {
        ans.push_front(cu.second);
        cu = pth[cu];
    } while(cu.first);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    int ai;
    while(cin >> n) {
        for (int i=0; i<n; i++) {
            cin >> ai;
            a[i] = ai;
        }
        deque<long long> dq = lis(n);
        cout << dq.size() << endl;

        for (int i=0; i<dq.size()-1; i++)
            cout << dq[i] << " ";
        cout << dq[dq.size()-1] << endl;
    }
}
