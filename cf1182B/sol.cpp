#include <bits/stdc++.h>
using namespace std;


const int MAXN = 502;
int grid[MAXN][MAXN];
bool vis[MAXN][MAXN];

int ver[MAXN];
int hor[MAXN];


bool iscenter(int i, int j) {
    if (grid[i-1][j] == 0 || grid[i][j-1] == 0)
        return false;
    
    if (grid[i+1][j] == 0 || grid[i][j+1] == 0)
        return false;

    return grid[i][j] == 1;
}

int main() {
    int h, w;
    cin >> h >> w;

    vector<pair <int, int>> g;

    string c;
    for (int i=1; i<=h; i++) {
        cin >> c;
        for (int j=1; j<=w; j++) {
            if (c[j-1] == '*')
                grid[i][j] = 1;
        }
    }
    
    bool exit = false;
    for (int i=1; i<=h; i++) {
        if (exit)
            break;
        for (int j=1; j<=w; j++) {
            if (iscenter(i, j)) {
                grid[i][j] = 0;

                for (int ii=i+1; ii<MAXN; ii++) {
                    if (grid[ii][j] == 0)
                        break;
                    grid[ii][j] = 0;
                    
                }
                
                for (int ii=i-1; ii>=0; ii--) {
                    if (grid[ii][j] == 0)
                        break;
                    grid[ii][j] = 0;
                }
                
                for (int jj=j-1; jj>=0; jj--) {
                    if (grid[i][jj] == 0)
                        break;
                    grid[i][jj] = 0;
                }
                
                for (int jj=j+1; jj<MAXN; jj++) {
                    if (grid[i][jj] == 0)
                        break;
                    grid[i][jj] = 0;
                }
                
                exit = true;
                break;
            }
        }
    }
    
    string res = "YES";
    for (int i=0; i<=h; i++) {
        for (int j=0; j<=w; j++) {
            if (grid[i][j] == 1)
                res = "NO";
        }
    }
    if (!exit)
        res = "NO";

    cout << res << endl;
}
