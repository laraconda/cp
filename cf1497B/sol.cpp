#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        int c = 0;
        map<int, int> ma;
        for (int i=0; i<n; i++) {
            int ai;
            cin >> ai;
            ai %= m;
            ma[ai]++;
        }

        if (ma[0] > 0) c++;
        for (auto& x : ma) {
            if (x.first != 0 && x.second != -1) {
                c += max(0, abs(x.second - ma[m - x.first]) - 1) + 1;
                ma[m - x.first] = -1;
            }
        }
        cout << c << endl;
    }
}
