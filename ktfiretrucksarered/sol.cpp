#include <bits/stdc++.h>
using namespace std;

const int MXN = 2e5 + 6;
int fssize[MXN];
int parent[MXN];

unordered_map<int, vector<int>> mymap;

void init_uf() {
    for (int i=0; i<MXN; i++) {
        fssize[i] = 1;
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
        if (fssize[a] < fssize[b])
            swap(a, b);
        parent[b] = a;
        fssize[a] += fssize[b];
    }
}

int main() {
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        int m;
        cin >> m;
        while (m--) {
            int ai;
            cin >> ai;
            mymap[ai].push_back(i);
        }
    }
    
    init_uf();
    vector<pair<pair<int, int>, int>> tree;
    for (auto& num_vec : mymap) {
        auto vec = num_vec.second;
        for (int i=1; i < (int)vec.size(); i++) {
            if (fs(vec[i-1]) != fs(vec[i])) {
                us(vec[i-1], vec[i]);
                tree.push_back({{vec[i-1], vec[i]}, num_vec.first});
            }
        }
    }
    if (tree.size() < n-1) {
        cout << "impossible" << endl;
    } else {
        for (auto x : tree) {
            cout << x.first.first << " " << x.first.second << " " << x.second << endl;
        } 
    }
}
