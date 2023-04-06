#include <bits/stdc++.h>
using namespace std;

const int NINF = 1e9 * (-1);
const int MXN = 105;
vector<pair<int, pair<int, int>>> es;
int A[MXN][MXN];

int size[MXN];
int parent[MXN];

void init_uf() {
    for (int i=0; i<MXN; i++) {
        size[i] = 1;
        parent[i] = i;
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
        if (a < b)
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}

void minit() {
    for (int i=0; i<MXN; i++) {
        for (int j=0; j<MXN; j++) {
            if (i == j) A[i][j] == 0;
            A[i][j] = NINF;
        }
    }
    es.clear();
    init_uf();
}



int main() {
    int C, S, Q;
    cin >> C >> S >> Q;

    int z = 1;
    while (C != 0 || S != 0 || Q != 0) {
        minit();

        int ai, bi, wi;
        while (S--) {
            cin >> ai >> bi >> wi;
            es.push_back({wi, {ai, bi}});
        }

        sort(es.begin(), es.end());

        for (pair<int, pair<int, int>> e : es) {
            if (fs(e.second.first) == fs(e.second.second)) continue;
            us(e.second.first, e.second.second);
            A[e.second.first][e.second.second] = e.first;
            A[e.second.second][e.second.first] = e.first;
        }

        fordf(C);

        cout << "Case #" << z++ << endl;
        int q1, q2;
        while (Q--) {
            cin >> q1 >> q2;
            if (A[q1][q2] == NINF)
                cout << "no path" << endl;
            else
                cout << A[q1][q2] << endl;
        }

        cin >> C >> S >> Q;
        if (C != 0 || S != 0 || Q != 0)
            cout << endl;
    }
}

