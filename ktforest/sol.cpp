#include <bits/stdc++.h>
using namespace std;

const int MXN = 1004;
const long long INF = 1e18;
typedef pair<long long, int> pli;
priority_queue<pli, vector<pli>, greater<pli>> q;

vector<pair<long long, int>> g[MXN];

long long dist[MXN];
long long dp[MXN];


void mclean() {
    for (int i=0; i<MXN; i++)
        dp[i] = -1;
    dp[2] = 1;
    for (int i=0; i<MXN; i++)
        g[i].clear();
}


void dij(int s) {
    fill(dist, dist + MXN, INF);
    dist[s] = 0;
    q.push({0, s});
    while (!q.empty()) {
        auto v = q.top(); q.pop();
        if (v.first > dist[v.second]) continue;
        for (auto ne : g[v.second]) {
            if (dist[ne.second] > ne.first + dist[v.second]) {
                dist[ne.second] = ne.first + dist[v.second];
                q.push({dist[ne.second], ne.second});
            }
        }
    }
}


long long paths(int i) {
    if (dp[i] != -1) return dp[i];
    long long ps = 0;
    for (auto ne : g[i]) {
        if (dist[ne.second] < dist[i])
            ps += paths(ne.second);
    }
    return dp[i] = ps;
}


int main() {
    int n, m;
    while (cin >> n && cin >> m) {
        mclean();

        for (int i=0; i<m; i++) {
            int a, b;
            cin >> a >> b;
            long long d;
            cin >> d;
            g[a].push_back({d, b});
            g[b].push_back({d, a});
        }

        dij(2);
        cout << paths(1) << endl;
    }

}
