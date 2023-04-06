#include <bits/stdc++.h>
using namespace std;

const int MXN = 1024;
vector<pair<int, int>> g[MXN];
int k[MXN][MXN];
int vis[MXN];


void bfs(int s) {
    queue<int> q;
    q.push(s);
    while(!q.empty()) {
        int v = q.front(); q.pop();
        for (pair<int, int> ne: g[v]) {
            for (int i=0; i<MXN; i++) {
                if (k[v][i] == 0 && !(v == s && i == 0)) continue;
                int o = (i | ne.first);
                k[ne.second][o] = 1;
            }
            if (!vis[ne.second]) { 
                q.push(ne.second);
                vis[ne.second] = 1;
            }    
        }
    }

}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int ai, bi, wi;
    while (m--) {
        cin >> ai >> bi >> wi;
        g[ai].push_back({wi, bi});
        g[bi].push_back({wi, ai});
    }

    int a, b;
    cin >> a >> b;

    bfs(a);
    int ans = -1;
    for (int i=0; i<MXN; i++) {
        if (k[b][i] == 1) {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
}
