#include <bits/stdc++.h>
using namespace std;

const int MXN = 128;
long long arr[MXN];

long long binpow(int a, int b) {
    if (b == 0) return 1;
    if (b == 1) return a;

    if (b & 1) {
        return a * binpow(a, b - 1);
    } else {
        long long res = binpow(a, b / 2);
        return res * res;
    }
}

void prec() {
    for (int i=1; i<MXN; i++) {
        long long p = binpow(i, 9);
        arr[i] = p;
    }
}

int main() {
    long long n;
    cin >> n;

    prec();

    int res;
    for (int i=1; i<MXN; i++) {
        if (n % arr[i] == 0)
            res = i;
    }

    cout << res << endl;
}
