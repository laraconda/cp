#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        map<int, int> m;
        int last;
        for (int i=0; i<n; i++) {
            int ai;
            cin >> ai;
            a.push_back(ai);
            m[ai]++;
            last = ai;
        }
        if (m[last] == n) cout << "NO" << endl;
        else {
            set<pair<int, int>> es;
            cout << "YES" << endl;
            int b;
            int i = 0;
            for (int j=0; j<n; j++) {
                if (a[i] != a[j]) {
                    b = j;
                    es.insert({min(i, j), max(i, j)});
                } 
            }
            for (int j=0; j<n; j++) {
                if (a[i] == a[j]) {
                    es.insert({min(b, j), max(b, j)});
                }
            }
            for (auto& e : es) {
                cout << e.first + 1 << " " << e.second + 1<< endl;
            }
        }
    }
}
