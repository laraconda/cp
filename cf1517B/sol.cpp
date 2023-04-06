#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                int bij;
                cin >> bij;
                q.push({bij, i});
            }
        }
        vector<vector<int>> M(n, vector<int>(m));
        int j = 0;
        while (j < m) {
            auto x = q.top(); q.pop();
            M[x.second][j] = x.first;
            j++;
        }
        while (!q.empty()) {
            auto x = q.top(); q.pop();
            for (int j=0; j<m; j++) {
                if (M[x.second][j] == 0) {
                    M[x.second][j] = x.first;
                    break;
                }
            }
        }

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) cout << M[i][j] << " ";
            cout << endl;
        }
    }
}
