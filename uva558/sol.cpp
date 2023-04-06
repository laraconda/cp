#include <bits/stdc++.h>
using namespace std;

const int MXN = 1004;
int dist[MXN];
vector<pair<int, int>> g[MXN];

bool bellman(int n) {
    dist[0] = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<MXN; j++) {
            for (pair<int, int> ne : g[j]) {
                int odist = dist[ne.second];
                dist[ne.second] = min(dist[ne.second], dist[j] + ne.first);
                if (i == n-1 && odist != dist[ne.second])
                    return true;
            }
        }
    }
    return false;
}


void mclear() {
    for (int i=0; i<MXN; i++) {
        dist[i] = INT_MAX;
        g[i].clear();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int c;
    cin >> c;
    while (c--) {
    mclear();
    int n, m;
    cin >> n >> m;

    int ai, bi, wi;
    while (m--) {
        cin >> ai >> bi >> wi;
        g[ai].push_back({wi, bi});
    }

    if (bellman(n)) {
        cout << "possible" << endl;
    } else {
        cout << "not possible" << endl;
    }

    }

}
