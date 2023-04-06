#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;

    vector<int> groups[n+1];
    for (int i=1; i<=n; i++) {
        groups[i].push_back(i);
        int val = i;
        while (true) {
            int nmod = val % n;
            if (nmod != 0)
                val = val + n + 1;
            else
                val = val + 1;

            if (val <= n*n)
                groups[i].push_back(val);
            else
                break;
        }
    }

    for (int i=1; i<=n; i++) {
        for (int j=0; j < n - 1; j++) {
            cout << groups[i][j] << " ";
        }
        cout << groups[i][n - 1] << endl;
    }
}
