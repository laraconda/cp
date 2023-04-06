#include <bits/stdc++.h>
using namespace std;


const int MXN = 1e5*2 + 4;
vector<int> g[MXN];
int gc[MXN];
int gnn[MXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int C, P, X, L;
    cin >> C >> P >> X >> L;

    int ai, bi;
    for (int i=0; i<P; i++) {
        cin >> ai >> bi;
        g[ai].push_back(bi);
        g[bi].push_back(ai);
    }

    for (int i=0; i<=C; i++) {
        gnn[i] = g[i].size();
    }

    queue<int> q;
    q.push(L);
    gc[L] = 1;
    while(!q.empty()) {
        int v = q.front(); q.pop();
        for (int ne : g[v]) {
            if (gc[ne] == 1)
                continue;
            gnn[ne]--;
            if (gnn[ne] <= g[ne].size()/2) {
                gc[ne] = 1;
                q.push(ne);
            }
        }
    }

    string res;
    if (gc[X] == 0)
        res = "stay";
    else
        res = "leave";

    cout << res << endl;
}
