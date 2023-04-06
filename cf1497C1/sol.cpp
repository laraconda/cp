#include <bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> sol(3);
        if (n % 3 == 0) {
            sol[0] = n/3;
            sol[1] = n/3;
            sol[2] = n/3;
        } else if (n % 4 == 0) {
            sol[0] = n/2;
            sol[1] = n/4;
            sol[2] = n/4;
        } else if (n % 4 == 2) {
            sol[0] = 2;
            sol[1] = (n-2) / 2;
            sol[2] = (n-2) / 2;
        } else if (n % 4 == 3 || n % 4 == 1){
            sol[0] = 1;
            sol[1] = (n-1) / 2;
            sol[2] = (n-1) / 2;
        }

        for (int x : sol)
            cout << x << " ";
        cout << endl;
    }
}
