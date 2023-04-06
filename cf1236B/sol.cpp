#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

long long binpow(long long a, long long b) {
    if (b == 1)
        return a % MOD;
    if (b & 1)
        return (binpow(a, b - 1) * a) % MOD;
    else {
        long long half = binpow(a, b/2);
        return (half * half) % MOD;
    }
}

int main() {
    long long n, m;
    cin >> n >> m;

    long long res = binpow(binpow(2, m) - 1, n);
    cout << res << endl;
}
