#include <bits/stdc++.h>
using namespace std;

const int MXN = 1000;
int parent[MXN];
int size[MXN];

vector <pair<double, pair<int, int>>> pes;

void init_uf() {
    for (int i=0; i<MXN; i++) {
        parent[i] = i;
        size[i] = 1;
    }
}

int fs(int v) {
    if (parent[v] == v)
        return v;
    return parent[v] = fs(parent[v]);
}

void us(int a, int b) {
    a = fs(a);
    b = fs(b);
    if (a != b) {
        if (a < b)
            swap(a, b);
        size[a] += size[b];
        parent[b] = a;
    }
}

double dist(pair<int, int> a, pair<int, int> b) {
    return (double)sqrt(
        (double)pow(a.first - b.first, 2) +
        (double)pow(a.second - b.second, 2));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        init_uf();
        int n;
        cin >> n;
        vector <pair<int, int>> ns(n+3);;

        int ai, bi;
        for (int i=1; i<=n; i++) {
            cin >> ai >> bi;
            ns[i] = {ai, bi}; 
        }

        for (int i=1; i<= n; i++) {
            for (int j=i+1; j<=n; j++) {
                pes.push_back({dist(ns[i], ns[j]), {i, j}});
            }
        }

        int m;
        cin >> m;
        while(m--) {
            cin >> ai >> bi;
            us(ai, bi);
        }

        vector<pair<int, int>> ans;

        sort(pes.begin(), pes.end());
        for (pair <double, pair<int, int>> e: pes) {
            if (fs(e.second.first) == fs(e.second.second))
                continue;
            us(e.second.first, e.second.second);
            ans.push_back({e.second.first, e.second.second});
        }
        
        for (pair<int, int> an : ans) {
            cout << an.first << " " << an.second << endl;
        }

        if (!ans.size())
            cout <<  "No new highways need" << endl;
        
        if (t != 0)
            cout << endl;

        ns.clear();
        pes.clear();
        ans.clear();
    }
}
