#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> rs(n);
        vector<vector<int>> cs(m);
        vector<vector<int>> sol(n);
        for (int i=0; i<n; i++) {
            vector<int> ri(m);
            for (int j=0; j<m; j++) {
                cin >> ri[j];
            }
            rs[i] = ri;
            vector<int> soli(m);
            sol[i] = soli;
        }
        for (int j=0; j<m; j++) {
            vector<int> cj(n);
            for (int i=0; i<n; i++) {
                cin >> cj[i];
            }
            cs[j] = cj;
        }
       
        for (int z=0; z<min(n, m); z++) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (rs[i][z] == cs[j][z]) {
                    for (int ii=0; ii<n; ii++) {
                        sol[ii][z] = cs[j][ii];
                    }
                    
                    for (int jj=0; jj<m; jj++) {
                        sol[z][jj] = rs[i][jj];
                    }
                    
                }
            }
        }
        }
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                cout << sol[i][j] << " ";
            }
            cout << endl;
        }
    }
}
