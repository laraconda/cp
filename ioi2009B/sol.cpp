#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int> > wss;

int mxworkers(int i, long long cpay, long long W, int N) {
    if (cpay > W) return 0;
    int tw = 1;
    double tpay = cpay;
    for (int j=0; j<N; j++) {
        if (i == j) continue;
        double pp = ((double)wss[j].second/wss[i].second) * cpay;
        if (pp >= wss[j].first) {
            if (tpay + pp > W) continue;
            tw++;
            tpay += pp;
        }
    }
    return tw;
}

bool ksort(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int main() {
    int N;
    long long W;
    cin >> N >> W;

    for (int i=0; i<N; i++) {
        int si, ki;
        cin >> si >> ki;
        wss.push_back({si, ki});
    }

    sort(wss.begin(), wss.end(), ksort);

    int mxw = 0;
    for (int i=0; i<N; i++) {
        long long cpay = wss[i].first;
        int a = mxworkers(i, cpay, W, N);
        if (a > mxw) mxw = a;
    }

    cout << mxw << endl;
    while (mxw--) {
        cout << 1 << endl;
    }
}
