#include <bits/stdc++.h>
using namespace std;

const int MXS = 1e4 + 6;

int main() {
    int t;
    cin >> t;
    for (int cas = 1; cas <= t; cas++) {
        int n, p;
        cin >> n >> p;

        vector<pair<int, long long>> ps(MXS);
        for (int i=0; i<n; i++) {
            int si;
            cin >> si;
            ps[si].first++;
        }

        long long total = 0;
        for (int i=0; i<MXS; i++) {
            total += ps[i].first;
            ps[i].second = total;
        }

        long long res = 1e18;
        for (int i=0; i<MXS; i++) {
            if (ps[i].second >= p) {
                long long hours = 0;
                int left = p - ps[i].first;
                for (int j=i-1; j>=0; j--) {
                    if (left <= 0) break;
                    hours += (i - j) * min(ps[j].first, left);
                    left -= min(ps[j].first, left);
                }
                if (left > 0) continue;
                res = min(res, hours);
            }
        }

        cout << "Case #" << cas << ": " << res << endl;
    }
}
