#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> X;
        vector<int> Y;
        for (int i=0; i<2*n; i++) {
            int xi, yi;
            cin >> xi >> yi;
            if (xi == 0) {
                Y.push_back(abs(yi)); 
            } else X.push_back(abs(xi));
        }

        sort(X.begin(), X.end());
        sort(Y.begin(), Y.end());

        ld td = 0;
        for (int i=0; i<X.size(); i++) {
            ld x = X[i];
            ld y = Y[i];
            td += sqrt(pow(x,2) + pow(y,2));
        }
        cout << setprecision(30) << td << endl;
    }
}
