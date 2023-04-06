#include <bits/stdc++.h>
using namespace std;

const int MXN = 1e4+5;
const int MXM = 1e5 +5;
vector<pair<int, pair<int, int>>> es;

int parent[MXN];
int size[MXN];

void init_uf() {
    for (int i=0; i<MXN; i++) {
        parent[i] = i;
        size[i] = 1;
    }
}

int fs(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = fs(parent[v]);
}

void us(int a, int b) {
    a = fs(a);
    b = fs(b);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        init_uf();

        int n, m;
        cin >> n >> m;

        int ai, bi, wi;
        long long tw = 0;
        for (int i=0; i<m; i++) {
            cin >> ai >> bi >> wi;
            es.push_back({wi, {ai, bi}});
            tw += wi;
        }

        sort(es.begin(), es.end());
        reverse(es.begin(), es.end());

        long long mstw = 0;
        for (pair<int, pair<int, int>> e: es) {
            if (fs(e.second.first) == fs(e.second.second))
                continue;
            mstw += e.first;
            us(e.second.first, e.second.second);
        }

        cout << tw - mstw << endl;
        es.clear();
    }
}
