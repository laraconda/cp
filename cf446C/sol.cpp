#include <bits/stdc++.h>
using namespace std;

const int MXN = 3e5 + 5;
const int MOD = 1e9 + 9;
int a[MXN];
int fib[MXN];
int accfib[MXN];


void prefib() {
    fib[1] = 1;
    accfib[1] = 1;
    fib[2] = 1;
    accfib[2] = 2;
    for (int i=3; i<MXN; i++) {
        fib[i] = ((long long)fib[i-1] + fib[i-2]) % MOD;
        accfib[i] = ((long long)accfib[i - 1] + fib[i]);
    }
}

struct ST {
    long long data;
    int l, h, lazyl, lazyh;
    ST* left;
    ST* right;

    ST(int l, int h): data(0), lazyl(-1), lazyh(-1), l(l), h(h) {
        if (l != h) {
            int m = l + (h - l)/2;
            left = new ST(l, m);
            right = new ST(m + 1, h);
        } else {
            data = a[l];
        }
    }

    void update(int ul, int uh) {
        if (uh < l || ul > h) return;
        if (ul <= l && h <= uh) {
            data += (accfib[h - l + 1]) % MOD;
            lazyl = ul;
            lazyh = uh;
        } else {
            push();
            left->update(ul, uh);
            right->update(ul, uh);
            data = (left->data + right->data) % MOD; 
        }
    }

    int query(int lq, int hq) {
        if (lq <= l && h <= hq) return data;
        if (hq < l || lq > h) return 0;
        push();
        return (left->query(lq, hq) + right->query(lq, hq)) % MOD;
    }

    void push() {
        left->l
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    prefib();

    for (int i=0; i<n; i++) {
        int ai;
        cin >> ai;
        a[i] = ai;
    }

    ST* st = new ST(1, n);
    for (int i=0; i<m; i++) {
        int type, l, r;
        cin >> type >> l >> r;
        if (type == 1) {
            st->update(l, r);
        } else {
            int res = st->query(l, r);
            cout << res << endl;
        }
    }
}
