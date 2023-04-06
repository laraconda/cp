#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<long long> score(n);
    vector<pair<int, long long>> hs(n);

    for (int i=0; i<n; i++) {
        int si;
        cin >> si;
        score[i] = si;
    }
    
    hs[0] = {0, score[0] * 100 - (n * k)};
    for (int i=1; i<n; i++) {
        long long x = score[i] * 100 - ((n - i) * k);
        if (hs[i-1].second <= x) hs[i] = {i, x};
        else hs[i] = hs[i-1];
    }

    long long m = 0;
    for (int i=n-1; i>=1; i--) {
       int dist = i - hs[i-1].first + 1;
       long long s = (score[hs[i-1].first] - score[i])* 100 - dist * k;
       if (s > m) m = s; 
    }

    cout << m << endl;
}
