#include <bits/stdc++.h>
using namespace std;

const int MAXN = (1e4 * 5) + 3;
const int MOD = 1e9 + 7;

int c[MAXN], aa[MAXN], bb[MAXN];
int n, a, b;

int A(int i);
int B(int i);

long long C(int i) {
    if (i <= 0)
        return 1;
    if (c[i] == -1)
        c[i] = ((long long)A(i) + B(i)) % MOD;
    return c[i];
}

int A(int i) {
    if (i <= 1)
        aa[i] = 1;
    else if (i <= a)
        aa[i] = C(i - 1);
    else if (aa[i] == -1)
        aa[i] = (MOD + ((C(i - 1) - B(i - a - 1)) % MOD)) % MOD;
    return aa[i];
}

int B(int i) {
    if (i <= 1)
        bb[i] = 1;
    else if (i <= b)
        bb[i] = C(i - 1);
    else if (bb[i] == -1)
        bb[i] = (MOD + ((C(i - 1) - A(i - b - 1)) % MOD)) % MOD;
    return bb[i];
}

int main() {
    cin >> n >> a >> b;

    for (int i=0; i<MAXN; i++) {
        c[i] = -1;
        aa[i] = -1;
        bb[i] = -1;
    }
    for (int i=1; i<=n; i++)
        C(i);
    cout << c[n] << endl;
}


