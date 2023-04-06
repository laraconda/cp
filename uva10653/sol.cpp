#include <bits/stdc++.h>
using namespace std;

const int MXN = 1004;
int grid[MXN][MXN];


void zeroes() {
    for (int i=0; i<MXN; i++) {
        for (int j=0; j<MXN; j++) {
            grid[i][j] = 0;
        }
    }
}

int main() {
    int R, C;
    cin >> R >> C;
    while (R != 0 || C != 0) {
        zeroes();

        int rb;
        cin >> rb;
        int r;
        int qn;
        int ci;
        while(rb--) {
            cin >> r >> qn;
            while (qn--) {
                cin >> ci;
                grid[r][ci] = -1;
            }
        }

        int sr, sc;
        int er, ec;

        cin >> sr >> sc;
        cin >> er >> ec;

        queue<pair <int, int>> q;
        q.push({sr, sc});
        grid[sr][sc] = 1;
        int dist;
        while (!q.empty()) {
            pair<int, int> v = q.front(); q.pop();
            dist = grid[v.first][v.second];

            if (v.first - 1 >= 0 && grid[v.first-1][v.second] == 0) {
                q.push({v.first-1, v.second});
                grid[v.first-1][v.second] = dist + 1;
            }
            if (v.first + 1 < R && grid[v.first+1][v.second] == 0) {
                q.push({v.first+1, v.second});
                grid[v.first+1][v.second] = dist + 1;
            }
            if (v.second - 1 >= 0 && grid[v.first][v.second-1] == 0) {
                q.push({v.first, v.second -1});
                grid[v.first][v.second - 1] = dist + 1;
            }
            if (v.second + 1 < C && grid[v.first][v.second + 1] == 0) {
                q.push({v.first, v.second + 1});
                grid[v.first][v.second + 1] = dist + 1;
            }
        }

        cout << grid[er][ec] - 1 << endl;
        
        cin >> R >> C;
    }
}
