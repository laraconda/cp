#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;

long long ga(long long n) {
    return n*(n+1)/2;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> ns;

    for (int i=0; i<n; i++) {
        int ni;
        cin >> ni;
        if (n - k < ni)
           ns.push_back(i);
    }

    long long res = 1;
    for (int i=0; i<ns.size() - 1; i++) {
        res *= ns[i+1] - ns[i];
        res %= MOD;
    }
    
    cout << ga(n) - ga(n-k) << " " << res << endl;
}
