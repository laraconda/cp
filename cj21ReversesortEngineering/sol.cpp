#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t=1; t<=T; t++) {
        int N, C;
        cin >> N >> C;
        bool pos = true;
        if (C < N-1) pos = false;
        if (C >= (N * (N + 1))/2) pos = false;
        vector<int>d(N-1, 1);
        C -= N-1;
        for (int i=N-2; i>=0; i--) {
            int mv = N-2 - i + 1;
            int v = min(mv, C);
            C-=v;
            d[i] += v;
        }

        vector<int> res(N);
        res[N-1] = N;
        for (int i=N-2; i>=0; i--) {
            int v = i + 1;
            int j = i + d[i] - 1;
            res[i] = v;
            reverse(res.begin() + i, res.begin() + j + 1);
        }
        
        cout << "Case #" << t << ": ";
        if (pos) {
            for (int i=0; i<(int)res.size()-1; i++) cout << res[i] << " ";
            cout << res.back();
        } else
            cout << "IMPOSSIBLE";
        cout << endl;
    }
}
