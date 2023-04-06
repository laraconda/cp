#include <bits/stdc++.h>
using namespace std;

const int MXN = 10005;
const long long INF = 1e16;
vector<pair<long long, int>> g[MXN];

typedef pair<long long, int> pli;

priority_queue<pli, vector<pli>, greater<pli>> q;
long long dist[MXN];
long long amin[MXN];
int alive[MXN];


void mclean() {
    fill(amin, amin + MXN, INF);
    fill(alive, alive + MXN, 1);
    for (int i=0; i<MXN; i++) {
        g[i].clear();
    }
    return;
}


int dijk(int s, int k) {
    fill(dist, dist + MXN, INF);
    q.push({0, s});
    dist[s] = 0;
    int killed = 0;
    if (alive[s]) killed++;
    alive[s] = 0;
    while (!q.empty()) {
        auto v = q.top(); q.pop();
        if (v.first > dist[v.second]) continue;
        if (v.first >= k) continue;
        for (auto ne : g[v.second]) {
            if (ne.first + dist[v.second] >= k) continue; 
            if (ne.first + dist[v.second] >= amin[ne.second]) continue;
            if (ne.first + dist[v.second] < dist[ne.second]) {
                if (alive[ne.second]) killed++;
                alive[ne.second] = 0;
                q.push({ne.first + dist[v.second], ne.second});
                dist[ne.second] = ne.first + dist[v.second];
                amin[ne.second] = dist[ne.second];
            }
        }
    }
    return killed;
}


int main() {
    int n, m, A, k;
    while (cin >> n >> m >> A >> k) {
        mclean();
        for (int i=0; i<m; i++) {
            int a, b, d;
            cin >> a >> b >> d;
            g[a].push_back({d, b});
            g[b].push_back({d, a});
        }
        int alive = n;
        for (int i=0; i<A; i++) {
            int bi;
            cin >> bi;
            int killed = dijk(bi, k);
            alive -= killed;
            cout << alive << endl;
        }
        cout << endl;
    }
}
