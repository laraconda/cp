#include <bits/stdc++.h>
using namespace std;

const int MXN = 2006;
const int NEG_INF = -1e8;
vector<pair<int, int>> ns;
vector<int> is;

int dp[MXN][MXN];

int K(int C, int i) {
    if (C < 0) return NEG_INF;
    if (C == 0 || (int)ns.size() == 0 || i < 0) return 0;
    if (dp[C][i] != -1)
        return dp[C][i];
    int res = max(K(C - ns[i].second, i-1) + ns[i].first, K(C, i-1));
    dp[C][i] = res;
    return dp[C][i];
}

void restart() {
    ns.clear();
    is.clear();
    for (int i=0; i<MXN; i++) {
        for (int j=0; j<MXN; j++) {
            dp[i][j] = -1;
        }
    }
}

void fillis(int C, int n) {
    int i = n - 1;
    while (i >= 0) {
        if (i == 0) {
            if (ns[0].first == dp[C][i])
                is.push_back(i);
            break;
        }
        else if (dp[C][i] > dp[C][i-1]) {
            is.push_back(i);
            C -= ns[i].second;
        }
        i--;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int C, n;
    while (cin >> C) {
        restart();

        cin >> n;
        for (int i=0; i<n; i++) {
            int v, w;
            cin >> v >> w;
            ns.push_back({v, w});
        }

        int maxv = K(C, n-1);
        fillis(C, n);

        cout << (int)is.size() << endl;
        for (int i=0; i<(int)is.size() - 1; i++) {
            cout << is[i] << " ";
        }
        if ((int)is.size() > 0)
            cout << is[is.size() - 1] << endl;
    }
}
