#include <bits/stdc++.h>
using namespace std;

const int MXN = 1e5 + 5;
long long ssum[MXN];
int msize[MXN];
int parent[MXN];
int singles[MXN];


void init_uf(int n) {
    for (int i=0; i<=n; i++) {
        msize[i] = 1;
        parent[i] = i;
        singles[i] = i;
        ssum[i] = i;
    }
}


int fs(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = fs(parent[v]);
}

int fss(int v) {
    return fs(singles[v]);
}


int gfs(int v) {
    int a = fs(v);
    int b = fss(v);
    if (singles[v] == v)
        return a;
    else
        return b;
}


void us(int a, int b) {
    a = gfs(a);
    b = gfs(b);

    if (a != b) {
        if (msize[a] < msize[b])
            swap(a, b);
        parent[b] = a;
        msize[a] += msize[b];
        ssum[a] += ssum[b];
    }
}

void moveone(int p, int a) {
    a = gfs(a);
    int pp = gfs(p);
    msize[pp]--;
    msize[a]++;
    ssum[a] += p;
    ssum[pp] -= p;

    singles[p] = a;
}

int main() {
    int n, m;
    while (cin >> n) {
    cin >> m;

    init_uf(n);
    while (m--) {

        int a;
        cin >> a;

        if (a == 1) {
            int p, q;
            cin >> p >> q;
            us(p, q);
        } else if (a == 2) {
            int p, q;
            cin >> p >> q;
            moveone(p, q); 
        } else if (a == 3) {
            int p;
            cin >> p;
            cout << msize[gfs(p)] << " " << ssum[gfs(p)] << endl;
        }
    }
    }
}
