#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, sx, sy;
    cin >> n >> m >> sx >> sy;
    int x = sx;
    int y = sy;
    cout << x << " " << y << endl;
    cout << 1 << " " << y << endl;
    int s = 1;
    x = 1, y = 1;
    while ((n % 2 != 0 && x <= n && y <= m) || (n % 2 == 0 && x <= n && y >= 1)) {
        if (!((x == sx && y == sy) || (x == 1 && y == sy)))
        cout << x << " " << y << endl;
        if (s == 1) {
            if (y == m) {x++; s = -1;}
            else y+=s;
        } else {
            if (y == 1) {x++; s = 1;}
            else y+=s;
        }
    }
    
}
