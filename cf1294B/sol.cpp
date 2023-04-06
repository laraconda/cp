#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<pair<int, pair<int, int>>> a;
        map<int, int> m;
        bool pos = true;
        for (int i=0; i<n;i++){
            int xi, yi;
            cin >> xi >> yi;
            a.push_back({xi + yi, {xi, yi}});
            m[xi + yi]++;
            if (m[xi + yi] > 1) pos = false;
        }
        sort(a.begin(), a.end());
        for (int i=1; i<n; i++) {
            int lastx = a[i-1].second.first;
            int lasty = a[i-1].second.second;
            
            int x = a[i].second.first;
            int y = a[i].second.second;
            if (x < lastx || y < lasty) pos = false;
        }
        if (pos) {
            cout << "YES" << endl;
            int cx = 0;
            int cy = 0;
            for (int i=0; i<n; i++) {
                auto p = a[i];
                int x = p.second.first;
                int y = p.second.second;
                
                int right = x - cx;
                while (right--) cout << "R";
                cx = x;
                int up = y - cy;
                while (up--) cout << "U";
                cy = y;
            }
            cout << endl;
        
        } else {
            cout << "NO" << endl;
        }
    }
}
