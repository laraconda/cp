#include <bits/stdc++.h>
using namespace std;

const int MXN = 104;
vector<pair<int, int>> g[MXN];

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
int dist[MXN];
bitset<MXN> vis;

void dijks(int s) {
    /*for (int i=0; i<MXN; i++)
        dist[MXN] = INT_MAX;*/
    
    dist[s] = 0;
    q.push({0, s});
    while (!q.empty()) {
        pair<int, int> v = q.top(); q.pop();
        if (v.first > dist[v.second]) continue;
        for (pair <int, int> ne : g[v.second]) {
            if (dist[v.second] + ne.first < dist[ne.second]) {
                dist[ne.second] = dist[v.second] + ne.first;
                q.push({dist[ne.second], ne.second});
            }
        }
    }
}

void mclean() {
    for (int i=0; i<MXN; i++) {
        g[i].clear();
        dist[i] = INT_MAX;
        vis.reset();
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        mclean();
        int N, E, T, M;
        cin >> N >> E >> T >> M;

        int a, b, w;
        while(M--) {
            cin >> a >> b >> w;
            g[b].push_back({w, a});
        }

        dijks(E);

        int ans = 0;
        for (int x : dist) {
            if (x <= T)
                ans++;
        }
        cout << ans << endl;
        if (t != 0)
            cout << endl;
    }
}
