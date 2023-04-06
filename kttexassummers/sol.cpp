#include <bits/stdc++.h>
using namespace std;

const int MXN = 2506;
const long long INF = 1e16;
vector<pair<long long, int>> g[MXN];
long long dist[MXN];
int par[MXN];

typedef pair<long long, int> pli;
priority_queue<pli, vector<pli>, greater<pli>> q;

long long fdist(pair<int, int> a, pair<int, int> b) {
    return pow(a.first - b.first, 2) + pow(a.second - b.second, 2);
}

void dijk(int s) {
    fill(dist, dist + MXN, INF);
    dist[s] = 0;
    q.push({0, s});
    par[s] = s;
    while (!q.empty()) {
        auto v = q.top(); q.pop();
        if (v.first > dist[v.second]) continue;
        for (auto ne : g[v.second]) {
            if (ne.first + dist[v.second] < dist[ne.second]) {
                dist[ne.second] = ne.first + dist[v.second];
                q.push({ne.first + dist[v.second], ne.second});
                par[ne.second] = v.second;
            }
        }
    }  
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> shads;
    for (int i=0; i<n+2; i++) {
        int x, y;
        cin >> x >> y;
        shads.push_back({x, y});
    }

    for (int i=0; i<n+2; i++) {
        for (int j=0; j<n+2; j++) {
            if (i == j) continue;
            g[i].push_back({fdist(shads[i], shads[j]), j});
        }
    }

    dijk(n);
    int curr = n+1;
    vector<int> path;
    while (curr != n) {
        if (curr != n+1) path.push_back(curr);
        curr = par[curr];
    }

    reverse(path.begin(), path.end());

    if (path.size() > 0) {
        for (int p : path) {
            cout << p << endl;
        } 
    } else {
        cout << "-" << endl;
    }
}
