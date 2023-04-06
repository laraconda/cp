#include<bits/stdc++.h>
using namespace std;

const int MXN = 1004;
const int INF = 1e9;

char A[MXN][MXN];
int P[MXN][MXN];
int F[MXN][MXN];
int V[MXN][MXN];

vector<int> nesy = {-1, 0, +1, 0};
vector<int> nesx = {0, +1, 0, -1};


void clearV() {
    for (int i=0; i<MXN; i++) {
        for (int j=0; j<MXN; j++) {
            V[i][j] = 0;
        }
    }
}

void bfsf(pair<int, int> start, int w, int h) {
    queue<pair<int, int>> q;
    q.push(start);
    F[start.second][start.first] = 0;
    while(!q.empty()) {
        auto v = q.front(); q.pop();
        for (int i=0; i<4; i++) {
            pair<int, int> u = {v.first + nesx[i], v.second + nesy[i]};
            if (u.first < 1 || u.second < 1 || u.first > w || u.second > h)
                continue;
            if (A[u.second][u.first] == '#' || A[u.second][u.first] == '*')
                continue;

            if (F[v.second][v.first] + 1 < F[u.second][u.first]) {
                q.push(u);
                F[u.second][u.first] = F[v.second][v.first] + 1;
            }
        } 
    }
}

void bfsp(pair<int, int> start, int w, int h) {
    queue<pair<int, int>> q;
    q.push(start);
    P[start.second][start.first] = 0;
    V[start.second][start.first] = 1;
    while(!q.empty()) {
        auto v = q.front(); q.pop();
        for (int i=0; i<4; i++) {
            pair<int, int> u = {v.first + nesx[i], v.second + nesy[i]};
            if (u.first < 0 || u.second < 0 || u.first > w + 1 || u.second > h + 1)
                continue;
            if (A[u.second][u.first] == '#')
                continue;
            if (F[u.second][u.first] <= P[v.second][v.first] + 1)
                continue;

            if (!V[u.second][u.first]) {
                V[u.second][u.first] = 1;
                q.push(u);
                P[u.second][u.first] = P[v.second][v.first] + 1;
            }
        } 
    }
}

void cleanup() {
    clearV();
    for (int i=0; i<MXN; i++) {
        for (int j=0; j<MXN; j++) {
            F[i][j] = INF;
            P[i][j] = INF;
            A[i][j] = '.';
        }
    }
}

int findres(int w, int h) {
    int res = INF;
    for (int i=0; i < w + 2; i++)
        res = min(res, P[0][i]);
    for (int i=0; i < w + 2; i++)
        res = min(res, P[h + 1][i]);
    
    for (int i=0; i < h + 2; i++)
        res = min(res, P[i][0]);
    for (int i=0; i < h + 2; i++)
        res = min(res, P[i][w + 1]);
    return res;
} 


int main() {
    int t;
    cin >> t;
    while (t--) {
        cleanup();

        int w, h;
        cin >> w >> h;

        pair<int, int> person;
        vector<pair<int, int>> fires;
        for (int i=1; i<=h; i++) {
            for (int j=1; j<=w; j++) {
                char c;
                cin >> c;
                A[i][j] = c;
                if (c == '@') {
                    person = {j, i};
                }

                if (c == '*')
                    fires.push_back({j, i});
            }
        }

        for (auto f : fires) {
            bfsf(f, w, h);
        }

        bfsp(person, w, h);

        int res = findres(w, h);
        if (res == INF)
            cout << "IMPOSSIBLE" << endl;
        else
            cout << res << endl;
    
    }
}
