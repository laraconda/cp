#include <bits/stdc++.h>
using namespace std;

const int MXN = 1e4+5;
const long long INF = 1e18;
long long dist[MXN];
typedef pair<long long, int> pli;
vector<pli> g[MXN];
priority_queue <pli, vector<pli>, greater<pli>> q;


void dijks(int s) {
    fill(dist, dist + MXN, INF);
    dist[s] = 0;
    q.push({0, s});
    while(!q.empty()) {
        pli v = q.top(); q.pop();
        if (v.first > dist[v.second]) continue;
        for (pli ne : g[v.second]) {
            if (dist[v.second] + ne.first < dist[ne.second]) {
                dist[ne.second] = dist[v.second] + ne.first;
                q.push({dist[ne.second], ne.second});
            }
        }
    }
}

void mset() {
    for (int i=0; i<MXN; i++) {
        // dist[i] = INT_MAX;
        g[i].clear();
    }

}

int main() {

    int n, m, q, s;
    cin >> n >> m >> q >> s;
    while (n != 0 || m != 0 || q != 0 || s != 0) {
        mset();
        int ai, bi, wi;
        while(m--) {
            cin >> ai >> bi >> wi;
            g[ai].push_back({wi, bi});
        }

        dijks(s);

        int qi;
        while(q--) {
            cin >> qi;
            if (dist[qi] == INF)
                cout << "Impossible" << endl;
            else
                cout << dist[qi] << endl;
        }
        cin >> n >> m >> q >> s;
        if (n != 0 || m != 0 || q != 0 || s != 0)
            cout << endl;
        
    }
}
