#include <bits/stdc++.h>
using namespace std;

vector<long long> kk;
int main() {
    int n = 0;
    cin >> n;

    for (int i=0; i<n; i++) {
        long long ai = 0;
        cin >> ai;
        kk.push_back(ai);
    }

    int maxs = 1;
    int cs = 1;
    for (int i=0; i < n-1; i++) {
        if (kk[i+1] <= 2*kk[i])
            cs++;
        else {
            cs = 1;
        }
        if (maxs < cs)
            maxs = cs;
    }

    cout << maxs << endl;
}
