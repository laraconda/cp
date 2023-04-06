#include <bits/stdc++.h>
using namespace std;


int main() {
    int q;
    cin >> q;
    while (q--) {
        int n, r;
        cin >> n >> r;

        set<int, greater<int>> xs;
        for (int i=0; i<n; i++) {
            int xi;
            cin >> xi;
            xs.insert(xi);
        }
        
        int count = 0;
        long long cum = 0;
        for (auto it = xs.begin(); it != xs.end(); it++) {
            if (*it - cum <= 0) break;
            count++;
            cum += r;
        }

        cout << count << endl;
        xs.clear();
    }
} 
