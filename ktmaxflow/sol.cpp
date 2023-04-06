#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MXN = 505, INF = 1e9;
const bool scale = false;
int dist[MXN], ptr[MXN], src, dest, lim = 1;

struct Edge {
    int to, rev, f, cap;
};

vector<Edge> G[MXN];

void add_edge(int v, int u, int c, int r = 0) {
    G[v].push_back({u, (int)G[u].size(), 0, c});
    G[u].push_back({v, (int)G[v].size() - 1, 0, r});
}

bool bfs() {
    queue<int> q ({src});
    fill(dist, dist + MXN, -1);
    dist[src] = 0;
    while (!q.empty() && dist[dest] == -1) {
        int v = q.front(); q.pop();
        for (Edge e: G[v]) {
            int u = e.to;
            if (dist[u] == -1 && e.f < e.cap && 
                (!scale || e.cap - e.f >= lim)) {
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    }
    return dist[dest] != -1;
}

int dfs(int v, int f) {
    if (v == dest || !f) return f;
    for (int &i = ptr[v]; i< G[v].size(); i++) {
        Edge &e = G[v][i];
        int u = e.to;
        if (dist[u] != dist[v] + 1) continue;
        if (int df = dfs(u, min(f, e.cap - e.f))) {
            e.f += df;
            G[u][e.rev].f -= df;
            return df;
        }
    }
    return 0;
}

ll dinic() {
    ll mf = 0;
    for (lim = (scale ? (1 << 30) : 1); lim > 0; lim >>= 1) {
        while (bfs()) {
            fill(ptr, ptr + MXN, 0);
            while (ll pushed = dfs(src, INF))
                mf += pushed;
        }
    }
    return mf;
}


int main() {
    int n, m;
    cin >> n >> m;
    cin >> src >> dest;

    while (m--) {
        int v, u, c;
        cin >> v >> u >> c;
        add_edge(v, u, c);
    }

    int res = dinic();
    int edges_used = 0;
    vector<pair<pair<int, int>, int>> es;
    for (int i=0; i<MXN; i++) {
        vector<Edge> ve = G[i];
        for (Edge e : ve) {
            if (e.f > 0) {
                edges_used++;
                es.push_back({{i, e.to}, e.f});
            }
        }
    }
    cout << n << " " << res << " " << edges_used << endl;
    
    for (int i=0; i<es.size(); i++) {
        cout << es[i].first.first << " " << es[i].first.second << " " << es[i].second << endl; 
    }
}
