#include <bits/stdc++.h>
using namespace std;

const int MXN = 1e5 + 5;
int pos[MXN];
int fine[MXN];

struct ST {
    long long data, lazy;
    int l, h;
    ST* left;
    ST* right;

    ST(int l, int h): data(0), lazy(0), l(l), h(h) {
        if (l != h) {
            int m = l + (h - l)/2;
            left = new ST(l, m);
            right = new ST(m + 1, h);
        }
    }

    void update(int ul, int uh, long long vadd) {
        if (uh < l || ul > h) return;
        if (ul <= l && h <= uh) {
            data += vadd * (h - l + 1);
            lazy += vadd;
        } else {
            push();
            left->update(ul, uh, vadd);
            right->update(ul, uh, vadd);
            data = left->data + right->data; 
        }
    }

    int query(int lq, int hq) {
        if (lq <= l && h <= hq) return data;
        if (hq < l || lq > h) return 0;
        push();
        return left->query(lq, hq) + right->query(lq, hq); 
    }

    void push() {
        left->data += lazy;
        left->lazy += lazy;
        right->data += lazy;
        right->lazy += lazy;
        lazy = 0;
    }
};


int main() {
    int n;
    cin >> n;
    
    for (int i=1; i<=n; i++) {
        int ai;
        cin >> ai;
        pos[ai] = i;
    }

    vector<int> sec;
    for (int i=1; i<= n; i++) {
        int ai;
        cin >> ai;
        sec.push_back(ai);
    }

    ST* st = new ST(1, n);

    for (int i=n-1; i>=0; i--) {
        int target = pos[sec[i]];
        int res = st->query(1, target);
        if (res)
            fine[sec[i]] = 1;
        st->update(target, target, 1);
    }

    int res = 0;
    for (int i=1; i<=n; i++) {
        res += fine[i];
    }

    cout << res << endl;
}
