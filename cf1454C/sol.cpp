#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<int, pair<int, int>> m;
        map<int, int> ma;
        int last = -1;
        for (int i=0; i<n; i++) {
            int ai;
            cin >> ai;
            if (m[ai].first == 0)
                m[ai].first = i+1;
            m[ai].second = i+1;
            ma[ai]++;
            if (ai == last) ma[ai]--;
            last = ai;
        }
        int mn = n+3;
        for (auto &x : m) {
            int c = 0;
            auto y = x.second;
            if (y.first != 1) c++;
            if (y.second != n) c++;
            c += ma[x.first] - 1;
            mn = min(mn, c);
        }
        cout << mn << endl;
    }
}
