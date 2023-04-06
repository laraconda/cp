#include <bits/stdc++.h>
using namespace std;

const int MXN = 2005;
int tasks[MXN];
vector<pair<pair<int, int>, int>> cs;
int m[MXN][MXN];


bool msort(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
    if (a.first.first == b.first.first) {
        if (a.first.second == b.first.second)
            return a.second < b.second;
        
        return a.first.second > b.first.second;
    }
    return a.first.first > b.first.first;
}

int main() {
    int N, T, P;
    cin >> N >> T >> P;

    for (int i=0; i<N; i++) {
        for (int j=0; j<T; j++) {
            int t;
            cin >> t;
            if (t == 0) tasks[j]++;
            m[i][j] = t; 
        }
    }
    
    for (int i=0; i<N; i++) {
        int nt = 0;
        int sc = 0;
        for (int j=0; j<T; j++) {
            if (m[i][j]) {
                nt++;
                sc += tasks[j];    
            }
        }
        cs.push_back({{sc, nt}, i+1});
    }

    sort(cs.begin(), cs.end(), msort);

    int sc, r;
    for (int i=1; i<=cs.size(); i++) {
        if (cs[i-1].second == P) {
            sc = cs[i-1].first.first;
            r = i;
        }
    }
    cout << sc << " " <<  r << endl;
}
