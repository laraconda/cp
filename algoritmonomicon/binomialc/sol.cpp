#include <bits/stdc++.h>
using namespace std;

const int MXN = 1e5 + 3, M = 1e9 + 7;
long long facts[MXN];
long long invs[MXN];

void prec() {
    facts[0] = 1;
    for (int i=1; i<MXN; i++)
        facts[i] = (i * facts[i - 1]) % M;
}

long long binpow(long long a, long long b) {
    a %= M;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % M;
        a = a * a % M;
        b >>= 1;
    }
    return res;
}

long long bc(int n, int k) {
    return (facts[n] * binpow(facts[k], M-2) % M * binpow(facts[n - k], M - 2)) % M;
}

int main() {
    prec();

    int q;
    cin >> q;
    while (q--) {
        int n, k;
        cin >> n >> k;

        cout << bc(n, k) << endl;
    }
}
