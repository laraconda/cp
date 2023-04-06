#include <bits/stdc++.h>
using namespace std;


int main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        
        vector<int> g(n+1);
        vector<int> current(n+1);
        vector<int> old(n+1);
        vector<int> days(n+1);
        
        for (int i=1; i<=n; i++) {
            int ai;
            cin >> ai;
            g[i] = ai;
            current[i] = i;
            old[i] = 0;
            days[i] = 0;
        }

        for (int i=1; i<n+4; i++) {
            for (int j=1; j<=n; j++) {
                int book;
                if (old[j] != 0) {
                    book = old[j];
                    old[j] = 0;
                } else {
                    book = current[j];
                    current[j] = 0;
                }
                old[g[j]] = current[g[j]];
                current[g[j]] = book; 
            }
            for (int j=1; j<=n; j++) {
                if (current[j] == j && days[j] == 0) {
                    days[j] = i;
                }
            }
        }

        for (int i=1; i<n; i++) {
            cout << days[i] << " ";
        }
        cout << days[n] << endl;
    }
}
