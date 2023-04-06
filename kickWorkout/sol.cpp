#include <bits/stdc++.h>
using namespace std;

priority_queue<long long, vector<long long>> q;

void mclear() {
    while (!q.empty()) {
        q.pop();
    }
}

int main() {
    int T;
    cin >> T;

    for (int t=1; t<=T; t++) {
        mclear();
        int n, k;
        cin >> n >> k;

        long long last = -1;
        for (int i=0; i<n; i++) {
            long long c;
            cin >> c;

            if (last != -1) {
                q.push(c - last);
            }
            last = c;
        }

        long long res = 0;
        for (int i=0; i<k; i++) {
            long long e = q.top(); q.pop();
            if (e == 1) {
                res = 1;
                break;
            }
            long long rem = e - e/2;
            q.push(e/2);
            q.push(rem);
        }
        if (!res) {
            res = q.top();
        }
        cout << "Case #" << t << ": " << res << endl;
    }
}
