#include <bits/stdc++.h>
using namespace std;

vector<int> ni = {0, -1, -1, -1, 0, 1, 1, 1};
vector<int> nj = {-1, -1, 0, 1, 1, 1, 0, -1};

bool mmid(vector<string>& grid, int i, int j, int n, int m) {
    bool pos = true;
    for (int z=0; z<8; z++) {
        int ii = i+ni[z];
        int jj = j+nj[z];

        if (ii < 0 || jj < 0 || ii >= n || jj >= m) {
            pos = false;
            break;
        }
        if (grid[ii][jj] != '#') pos = false;
    }
    return pos;
}

bool mpart(vector<string>& grid, int i, int j, int n, int m) {
    for (int z=0; z<8; z++) {
        int ii = i + ni[z];
        int jj = j + nj[z];
        if (ii < 0 || jj < 0 || ii >= n || jj >= m) continue;
        if (mmid(grid, ii, jj, n, m))
            return true;
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i=0; i<n; i++) {
        cin >> grid[i];
    }

    bool pos = true;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (grid[i][j] == '#') {
                if (!mpart(grid, i, j, n, m)) {
                    pos = false;
                    break;
                }
            }
        }
    }

    if (pos) cout << "YES"; else cout << "NO";
    cout << endl;
}
