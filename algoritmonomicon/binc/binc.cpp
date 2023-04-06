#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

long long fastpow(long long a, long long b) {
    if (b == 0)
        return 1;
    if (b & 1) {
        return (fastpow(a, b - 1) * a) % mod;
    } else {
        long long res = fastpow(a, b/2);
        return (res * res) % mod;
    }
}


int main() {
    
    int n, k;
    cin >> n >> k;

    long long factn, factk, factn_k, acc;
    factn_k = 1;
    acc = 1;
    for (int i=1; i<=n; i++) {
        acc = acc * i % mod;
        if (i == n)
            factn = acc;
        if (i == k)
            factk = acc;
        if (i == n-k)
            factn_k = acc;
    }

    long long res = (factn * fastpow(factk, mod - 2)) % mod;
    res = (res * fastpow(factn_k, mod - 2)) % mod;
    cout << res << endl;
    return 0;
}
