#include <bits/stdc++.h>
using namespace std;

const int MXN = 105;
const unsigned int INF = 1e7;
char A[MXN][MXN];
char V[MXN][MXN];
unsigned int D[3][MXN][MXN];

vector<int> nei = {-1, 0, 1, 0};
vector<int> nej = {0, 1, 0, -1};


void mclear() {
    for (int i=0; i<MXN; i++) {
        for (int j=0; j<MXN; j++) {
            A[i][j] = 'a';
            D[0][i][j] = INF;
            D[1][i][j] = INF;
            D[2][i][j] = INF;
        }
    }
}


void bfs(pair<int, int> s, int h, int w, int ii) {
    queue<pair<int, int>> q;
    q.push(s);
    D[ii][s.first][s.second] = 0;
    while (!q.empty()) {
        auto v = q.front(); q.pop();
        unsigned int doors = D[ii][v.first][v.second];
        for (int z=0; z<4; z++) {
            int i = v.first + nei[z];
            int j = v.second + nej[z];
            if (A[i][j] == '*' || i < 0 || j < 0 || i > h+1 || j > w+1)
                continue;
            if (A[i][j] == '#') {
                if (D[ii][i][j] > doors + 1) {
                    D[ii][i][j] = doors + 1;
                    q.push({i, j});
                }
            } else {
                if (D[ii][i][j] > doors) {
                    D[ii][i][j] = doors;
                    q.push({i, j});
                }
            }

        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
    mclear();
    
    int h, w;
    cin >> h >> w;

    vector<pair<int, int>> ps;
    ps.push_back({0, 0});
    for (int i=1; i<=h; i++) {
        for (int j=1; j<=w; j++) {
            char cij;
            cin >> cij;
            A[i][j] = cij;
            if (cij == '$') {
                ps.push_back({i, j});
            }
        }
    }

    for (int i=0; i<3; i++) {
        bfs(ps[i], h, w, i);
    }

    unsigned int res = INF;
    for (int i=0; i<=h+1; i++) {
        for (int j=0; j<=w+1; j++) {
            unsigned int extra = 0;
            if (A[i][j] == '#')
                extra = 2; 
            res = min(res, D[0][i][j] + D[1][i][j] + D[2][i][j] - extra);
        }
    }
    cout << res << endl;
    }
}
