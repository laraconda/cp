#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<long long> sav(n);
        for (int i=0; i<n; i++) {
            cin >> sav[i];
        }

        sort(sav.begin(), sav.end());

        int rich = 0;
        double un = 0;
        double av;
        for (int i=n-1; i>=0; i--) {
            un += sav[i];
            av = un/(n-i);
            if (av >= x) {
                rich++;
            }
        }

        cout << rich << endl;
    }
}
