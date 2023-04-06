#include <bits/stdc++.h>
using namespace std;

const int MXN = 2e5 + 5;
long long a[MXN];

struct ST {
    long long data, lazy;
    int l, h;
    ST* left;
    ST* right;

    ST(int l, int h): lazy(0), l(l), h(h) {
        if (l != h) {
            int m = l + (h - l)/2;
            left = new ST(l, m);
            right = new ST(m + 1, h);
            data = min(left->data, right->data);
        } else {
            data = a[l];
        }
    }

    void update(int ul, int uh, long long vadd) {
        if (uh < l || ul > h) return;
        if (ul <= l && h <= uh) {
            data += vadd;
            lazy += vadd;
        } else {
            push();
            left->update(ul, uh, vadd);
            right->update(ul, uh, vadd);
            data = min(left->data, right->data); 
        }
    }

    long long query(int lq, int hq) {
        if (lq <= l && h <= hq) return data;
        if (hq < l || lq > h) return 1e18;
        push();
        return min(left->query(lq, hq), right->query(lq, hq)); 
    }

    void push() {
        left->data += lazy; left->lazy += lazy;
        right->data += lazy; right->lazy += lazy;
        lazy = 0;
    }
};


int main() {
    int n, m;
    cin >> n;

    for (int i=0; i<n; i++) {
        long long ai;
        cin >> ai;
        a[i] = ai;
    }

    ST* st = new ST(0, n-1);

    cin >> m;
    cin.ignore();
    for (int i=0; i<m; i++) {
        string s;
        getline(cin, s);
        string sa[3];
        int z = 0;
        for (int j = 0; j < (int)s.size(); j++) {
            if (s[j] == ' ')
                z++;
            else
                sa[z].append(s, j, 1);
        }

        int ints[3];
        ints[0] = stoi(sa[0]);
        ints[1] = stoi(sa[1]);
        if (z == 2) {  // add
            ints[2] = stoi(sa[2]);
            if (ints[0] <= ints[1])
                st->update(ints[0], ints[1], ints[2]);
            else {
                st->update(ints[0], n - 1, ints[2]);
                st->update(0, ints[1], ints[2]);
            }
        } else {
            long long mi;
            if (ints[0] <= ints[1])
                mi = st->query(ints[0], ints[1]);
            else {
                mi = st->query(0, ints[1]);
                mi = min(mi, st->query(ints[0], n - 1));
            }
            cout << mi << endl;
        }
    }
}
