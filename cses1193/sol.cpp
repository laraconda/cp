#include<bits/stdc++.h>
using namespace std;

const int MXN = 1004;
int vis[MXN][MXN];
char path[MXN][MXN];
pair<int, int> parent[MXN][MXN];

pair<int, int> mstart, mend;

vector<int> auxi = {-1, 0, 1, 0};
vector<int> auxj = {0, 1, 0, -1};
vector<char> dirs = {'U', 'R', 'D', 'L'};

bool bfs(int n, int m) {
    queue<pair<int, int>> q;
    q.push({mstart.first, mstart.second});
    vis[mstart.first][mstart.second] = 1;
    while (!q.empty()) {
        pair<int, int> v = q.front(); q.pop();
        if (v == mend) return true;
        
        int vi = v.first;
        int vj = v.second;
        for (int z=0; z < 4; z++) {
            int nvi = vi + auxi[z];
            int nvj = vj + auxj[z];

            if (nvi < 0 || nvj < 0) continue;
            if (nvi >= n || nvj >= m) continue;
            
            if (!vis[nvi][nvj]) {
                q.push({nvi, nvj});
                vis[nvi][nvj] = 1;
                path[nvi][nvj] = dirs[z]; 
                parent[nvi][nvj] = {vi, vj};
            }
        }
    }
    return false;
}


vector<char> getpath(int n, int m) {
    vector<char> ppath;
    int i = mend.first;
    int j = mend.second;
    while (i != mstart.first || j != mstart.second) {
        ppath.push_back(path[i][j]);
        pair<int, int> p = parent[i][j];
        i = p.first;
        j = p.second;
    }
    reverse(ppath.begin(), ppath.end());
    return ppath;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    cin.ignore();
    for (int i=0; i<n; i++) {
        string l;
        getline(cin, l);
        for (int j=0; j<m; j++) {
            vis[i][j] = 0;
            path[i][j] = '0';
            if (l[j] == 'A') {
                mstart = {i, j};
            } else if (l[j] == 'B') {
                mend = {i, j};
            } else if (l[j] == '#') {
                vis[i][j] = 1;
            }
        }
    }
    
    bool reachable = bfs(n, m);
    if (reachable) {
        cout << "YES" << endl;
        vector<char> ppath = getpath(n, m);
        cout << ppath.size() << endl;
        for (char p: ppath) {
            cout << p;
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }
}
