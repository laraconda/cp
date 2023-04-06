#include <bits/stdc++.h>
using namespace std;

const int MXN = 1e5 + 5;

int grid[3][MXN];

int main() {
    int n, q;
    cin >> n >> q;

    long long block = 0;
    while (q--) {
        int ri, ci;
        cin >> ri >> ci;
        grid[ri][ci]++;

        if (grid[ri][ci] % 2 == 0) {
            if (ci - 1 > 0) {
                if (grid[(ri == 1) ? 2:1][ci - 1] % 2 != 0)
                    block--;
            }
            
            if (grid[(ri == 1) ? 2:1][ci] % 2 != 0) {
                block--;
            }
            
            if (ci + 1 <= n) {
                if (grid[(ri == 1) ? 2:1][ci + 1] % 2 != 0)
                    block--;
            }
        } else {
            if (ci - 1 > 0) {
                if (grid[(ri == 1) ? 2:1][ci - 1] % 2 != 0)
                    block++;
            }
            
            if (grid[(ri == 1) ? 2:1][ci] % 2!= 0) {
                block++;
            }
            
            if (ci + 1 <= n) {
                if (grid[(ri == 1) ? 2:1][ci + 1] % 2 != 0)
                    block++;
            }
        }
        if (block > 0) cout << "NO"; else cout << "YES";
        cout << endl;
    }
}
