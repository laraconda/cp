#include <bits/stdc++.h>
using namespace std;

const int MXN = 19;
int A[MXN][MXN];
int V[MXN][MXN];
int E[MXN][MXN];
int N, R, C;
int MAXBS;

pair<int, int> start;

vector<int> nei = {-1, 0, 1, 0};
vector<int> nej = {0, 1, 0, -1};

void cleanbfs() {
    for (int i=0; i<MXN; i++) {
        for (int j=0; j<MXN; j++) {
            V[i][j] = 0;
            E[i][j] = -1;
        }
    }
}

bool bfs(int e) {
    cleanbfs();
    queue<pair<int, int>> q;
    q.push(start);
    V[start.first][start.second]++;
    E[start.first][start.second] = e;
    while (!q.empty()) {
        auto v = q.front(); q.pop();
        for (int z=0; z<4; z++) {
            int i = v.first + nei[z];
            int j = v.second + nej[z];
            if (i < 0 || j < 0 || i > R + 1 || j >= C || V[i][j] > N)
                continue;
            if (i == 0)
                return true;
            int cost = A[i][j];
            if (i == R + 1)
                cost = 0;
            if (E[v.first][v.second] - cost < 0)
                continue;
            if (E[i][j] < E[v.first][v.second] - cost) {
                E[i][j] = E[v.first][v.second] - cost;
                q.push({i, j});
                V[i][j]++;
            }
        }
    }
    return false;
}


int bs() {
    int low = 0;
    int high = MAXBS;
    while (low <= high) {
        int mid = low + (high - low)/2;
        bool res = bfs(mid);
        if (res)
            high = mid - 1;
        else
            low = mid + 1; 
    }
    return low;
}

int main() {
    cin >> R >> C;
    N = (R+2) * (C+2) * 5;
    MAXBS = N * 9; 
    start = {R + 1, 0};
    for (int i=0; i<=R+1; i++) {
        for (int j=0; j<C; j++) {
            if (i == 0 || i == R + 1) {
                char cij;
                cin >> cij;
            } else {
                int cij;
                cin >> cij;
                A[i][j] = cij;
            }

        }
    }

    int res = bs();
    cout << res << endl;
}
