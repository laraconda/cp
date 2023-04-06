#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> ys(m);
    vector<int> xs(n);
    vector<vector<bool>> g(n, vector<bool>(m));
    int c = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            char cij;
            cin >> cij;
            if (cij == '*') {
                ys[j]++;
                xs[i]++;
                c++;
                g[i][j] = true;
            }
        }
    }
    bool pos = false;
    int x,y;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            int k = 0;
            if (g[i][j]) k = 1;
            if (ys[j] + xs[i] - k == c) {
                pos = true;
                x = i+1;
                y = j+1;
            }
        }
    }
    if (pos) {
        cout << "YES" << endl;
        cout << x << " " << y << endl;
    } else {
        cout << "NO" << endl;
    }
}
