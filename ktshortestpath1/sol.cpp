#include <bits/stdc++.h>
using namespace std;

const int MXN = 1e4+5;
int dist[MXN];
vector<pair<int, int>> g[MXN];
priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;


void dijks(int s) {
    dist[s] = 0;
    q.push({0, s});
    while(!q.empty()) {
        pair<int, int> v = q.top(); q.pop();
        if (v.first > dist[v.second]) continue;
        for (pair<int, int> ne : g[v.second]) {
            if (dist[v.second] + ne.first < dist[ne.second]) {
                dist[ne.second] = dist[v.second] + ne.first;
                q.push({dist[ne.second], ne.second});
            }
        }
    }
}

void mset() {
    for (int i=0; i<MXN; i++) {
        dist[i] = INT_MAX;
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
            if (dist[qi] == INT_MAX)
                cout << "Impossible" << endl;
            else
                cout << dist[qi] << endl;
        }
        cin >> n >> m >> q >> s;
        if (n != 0 || m != 0 || q != 0 || s != 0)
            cout << endl;
        
    }
}
