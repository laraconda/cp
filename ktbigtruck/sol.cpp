#include <bits/stdc++.h>
using namespace std;

const int MXN = 106;
const int INF = 1e9;
vector<pair<int, int>> g[MXN];
int points[MXN];

int dist[MXN];
int pts[MXN];

typedef pair<int, int> pli;
priority_queue<pli, vector<pli>, greater<pli>> q;


void dkstra() {
    fill(dist, dist + MXN, INF);
    dist[1] = 0;
    pts[1] = points[1];
    q.push({0, 1});
    while (!q.empty()) {
        auto v = q.top(); q.pop();
        if (v.first > dist[v.second]) continue;
        for (auto ne : g[v.second]) {
            if (dist[v.second] + ne.first < dist[ne.second]) {
                dist[ne.second] = dist[v.second] + ne.first;
                pts[ne.second] = points[ne.second] + pts[v.second];
                q.push({dist[ne.second], ne.second});
            } else if (dist[v.second] + ne.first == dist[ne.second]) {
                if (pts[v.second] + points[ne.second] > pts[ne.second]) {
                    pts[ne.second] = pts[v.second] + points[ne.second];
                    q.push({dist[ne.second], ne.second});
                }
            }
        }
    }
}


int main() {
    int n;
    cin >> n;

    for (int i=1; i<=n; i++) {
        int ti;
        cin >> ti;
        points[i] = ti;
    }

    int m;
    cin >> m;

    while (m--) {
        int a, b, w;
        cin >> a >> b >> w;

        g[a].push_back({w, b});
        g[b].push_back({w, a});
    }

    dkstra(); 

    if (dist[n] == INF) {
        cout << "impossible" << endl;
    } else {
        cout << dist[n] << " " << pts[n] << endl;
    }

}
