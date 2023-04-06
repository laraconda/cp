#include <bits/stdc++.h>
using namespace std;

const int MXN = 1005;
const int INF = 1e8;
int ne[MXN][MXN];
int dis[MXN];

priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void dk(int s, int n) {
    fill(dis, dis + MXN, INF);
    dis[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        auto v = pq.top(); pq.pop();
        if (dis[v.second] < v.first) continue;
        for (int i=0; i<n; i++) {
            if (i == v.second) continue;
            int ed = ne[v.second][i];
            if (dis[i] > ed + v.first) {
                dis[i] = ed + v.first;
                pq.push({dis[i], i});
            }
        }
    }
}

int main() {
    int N, S, T;
    cin >> N >> S >> T;

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            int dij;
            cin >> dij;
            ne[i][j] = dij;
        }
    }

    dk(S, N);

    cout << dis[T] << endl;
}
