#include <bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        pair<int, int> a;
        pair<int, int> b;
        for (int i=0; i<n; i++) {
            string s;
            cin >> s;
            for (int j=0; j<n; j++) {
                if (i == j) continue;
                int ai = s[j] - '0';
                if (i == 0 && j == 1) a.first = ai;
                if (i == 1 && j == 0) a.second = ai;
                if (i == n-2 && j == n-1) b.first = ai;
                if (i == n-1 && j == n-2) b.second = ai;
            }
        }
        int c = 0;
        vector<pair<int, int>> x;
        if (a.first == a.second) {
            if (b.first == b.second) {
                if (b.first == a.first) {
                    c = 2;
                    x.push_back({0, 1});
                    x.push_back({1, 0});
                }
            } else {
                c = 1;
                if (b.first == a.first) x.push_back({n-2, n-1});
                else x.push_back({n-1, n-2});
            }
        } else {
            if (b.first == b.second) {
                c = 1;
                if (a.first == b.first) x.push_back({0, 1});
                else x.push_back({1, 0});
            } else {
                c = 2;
                if (a.first == 0) x.push_back({1, 0});
                else x.push_back({0, 1});
                if (b.first == 1) x.push_back({n-1, n-2});
                else x.push_back({n-2, n-1});
            } 
        }
        cout << c << endl;
        for (auto xi : x) cout << xi.first + 1 << " "  << xi.second + 1 << endl;
    }
}
