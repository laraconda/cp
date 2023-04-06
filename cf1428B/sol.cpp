#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        bool clockwisec = false;
        bool anticlockwisec = false;

        vector<pair<int, int>> g(n);
        for (int i=0; i<n; i++) {
            int ni = (i+1) % n; 
            if (s[i] == '<') {
                g[ni].first = 1;
            } else if (s[i] == '>') {
                g[i].second = 1;
            } else {
                g[ni].first = 1;
                g[i].second = 1;
            }
        }
        int size = 0;
        int i = 0;
        while (size < n) {
            if (g[i].first) {
                i--;
                if (i < 0) i = n-1;
                size++;
            } else break;
        }
        if (size == n) anticlockwisec = true;
        
        
        size = 0;
        i = 0;
        while (size < n) {
            if (g[i].second) {
                i++;
                i = i % n;
                size++;
            } else break;
        }
        if (size == n) clockwisec = true;

        int res = 0;
        if (anticlockwisec || clockwisec) {
            res = n; 
        } else {
            for (int i = 0; i<n; i++) {
                int pi = i-1;
                if (pi < 0) pi = n-1;
                int ni = (i+1) % n; 
                if (g[i].second && g[ni].first || g[i].first && g[pi].second)
                    res++;
            }
        }
        cout << res << endl;
    }
}
