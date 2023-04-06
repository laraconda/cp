#include<bits/stdc++.h>
using namespace std;


typedef long long ll;

const int MXN = 1e5, INF = 1e9;
const bool scale = false;
int dist[MXN], ptr[MXN], src, dest, lim = 1;

struct Edge {
    int to, rev, f, cap;
};

vector<Edge>G[MXN];

void add_edge(int v, int u, int c, int r = 0) {
    G[v].push_back({u, (int)G[u].size(), 0, c});
    G[u].push_back({v, (int)G[v].size() - 1, 0, r});
}

bool bfs() {
    queue<int> q({src});
    fill(dist, dist + MXN, -1);
    dist[src] = 0;
    while (!q.empty() && dist[dest] == -1) {
        int v = q.front(); q.pop();
        for (auto e: G[v]) {
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
    for (int &i = ptr[v]; i < G[v].size(); i++) {
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

    src = 0;
    dest = n - 1;

    while (m--) {
        int v, u, cap;
        cin >> v >> u >> cap;
        add_edge(v, u, cap);
    }

    cout << dinic() << endl;
}
