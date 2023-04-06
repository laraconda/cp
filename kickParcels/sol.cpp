#include <bits/stdc++.h>
using namespace std;

vector<int> ni = {-1, 0, 1, 0};
vector<int> nj = {0, 1, 0, -1};


void ff(pair<int, int> s, vector<vector<int>>& dist, int R, int C) {
    queue<pair<int, int>> q;
    q.push(s);
    dist[s.first][s.second] = 0;
    while (!q.empty()) {
        auto v = q.front(); q.pop();
        for (int z = 0; z < 4; z++) {
            int i = v.first + ni[z];
            int j = v.second + nj[z];

            if (i < 0 || j < 0 || i >= R || j >= C) continue;

            if (dist[i][j] > dist[v.first][v.second] + 1) {
                dist[i][j] = dist[v.first][v.second] + 1;
                q.push({i, j});
            }
        }
    }
}


void dcopy(vector<vector<int>>& a, vector<vector<int>>& b) {
    for (int i=0; i<a.size(); i++) {
        for (int j=0; j<a[i].size(); j++) {
            b[i][j] = a[i][j];        
        }
    }
}


int findov(vector<vector<int>>& a) {
    int ov = -1;
    for (int i=0; i<a.size(); i++) {
        for (int j=0; j<a[i].size(); j++) {
            if (ov < a[i][j])
                ov = a[i][j];
        }
    }
    return ov;
}



int main() {
    int T;
    cin >> T;
    for (int t=1; t<=T; t++) {
        int R, C;
        cin >> R >> C;
        vector<vector<int>> grid(R);
        vector<vector<int>> dist(R);
        vector<vector<int>> ndist(R);
        for (int i=0; i<R; i++) {
            grid[i].resize(C);
            dist[i].resize(C);
            ndist[i].resize(C);
        }

        cin.ignore();
        for (int i=0; i<R; i++) {
            string li;
            getline(cin, li);
            for (int j=0; j<(int)li.size(); j++) {
                grid[i][j] = 0;
                if (li[j] == '1')
                    grid[i][j] = 1;
                dist[i][j] = 1e9;
            }
        }
        for (int i=0; i<R; i++) {
            for (int j=0; j<C; j++) {
                if (grid[i][j])
                    ff({i, j}, dist, R, C);
            }
        }
        int res = findov(dist);
        for (int i=0; i<R; i++) {
            for (int j=0; j<C; j++) {
                if (!grid[i][j]) {
                    dcopy(dist, ndist);
                    ff({i, j}, ndist, R, C);
                    int ov = findov(ndist);
                    if (ov < res) res = ov;
                }
            }
        }

        cout << "Case #" << t << ": " << res << endl;
    }
}
