#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> classes(n+1);
    vector<int> bs(n+1);
    for (int i=0; i<n; i++) {
        int bi;
        cin >> bi;
        classes[i+1] = (i+1) - bi;
        bs[i+1] = bi;
    }

    map<int, long long> vals;
    for (int i=1; i<=n; i++) {
       vals[classes[i]] += bs[i];
    }
    
    long long mmax = 0;
    for (auto& c_v : vals)
       mmax = max(c_v.second, mmax);

    cout << mmax << endl;
}
