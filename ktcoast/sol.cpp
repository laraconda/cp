#include <bits/stdc++.h>
using namespace std;

const int MXN = 1005;
int A[MXN][MXN];
int vis[MXN][MXN];

vector<int> ni = {-1, 0, 1, 0};
vector<int> nj = {0, 1, 0, -1};


int bfs(int n, int m) {
    int coast = 0;
    queue<pair<int, int>> q;
    q.push({0, 0});
    vis[0][0] = 1;
    while (!q.empty()) {
        auto v = q.front(); q.pop();
        for (int z=0; z<4; z++) {
            int i = v.first + ni[z];
            int j = v.second + nj[z];

            if (i < 0 || j < 0 || i > (n + 1) || j > (m + 1))
                continue;
            if (A[i][j] == 1) {
                coast++;
            } else if (!vis[i][j]) {
               q.push({i, j});
               vis[i][j] = 1;
            }
        }
    }
    return coast;
}


int main() {
    int n, m;
    cin >> n >> m;
 
    cin.ignore();
    for (int i=1; i <= n; i++) {
        string s;
        getline(cin, s);
        for (int j=0; j < m; j++) {
            if (s[j] == '0')
                A[i][j+1] = 0;
            else
                A[i][j+1] = 1;
        }
    }

    int coast = bfs(n, m);
    cout << coast << endl;
}
