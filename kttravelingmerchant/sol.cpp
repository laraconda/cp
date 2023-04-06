#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;

    vector<vector<long long>> mat(7);
    vector<long long> adds(n);
    for (int i=0; i<7; i++)
        mat[i] = vector<long long>(n);
        // checar si son 0 los vals por defecto

    for (int i=0; i<n; i++) {
        long long vi;
        cin >> vi;
        mat[i][0] = vi;
        long long add;
        cin >> add;
        adds[i] = add;
    }

    for (int j=0; j<n; j++) {
        for (int i=0; i<7; i++) {
            int mult = 0;
            if (i <= 3) {
                mult = i;
            } else {
                mult = 3 - (i % 3);
            }
            mat[i][j] = mat[0][j] + adds[j] * mult; 
        }
    }


    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
    
    }
}
