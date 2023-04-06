#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t=1; t<=T; t++) {
        int n, b;
        cin >> n >> b;

        vector<int> as(n);
        for (int i=0; i<n; i++) {
            int ai;
            cin >> ai;

            as[i] = ai;
        }

        sort(as.begin(), as.end());

        long long sf = 0;
        int res = 0;
        for (int i=0; i<n; i++) {
            if (sf + as[i] <= b) {
                sf += as[i];
                res++;
            } else break;
        }
        cout << "Case #" << t << ": " << res << endl;
    }
}
