#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1802;
long long kount[MAXN];
long long w[MAXN];
long long wo[MAXN];


long long kountf(int, int);

long long wof(int n, int k) {
    if (n == 1)
        return k-1;
    long long res = wo[n];
    if (res == 0)
        res = kountf(n-1, k) * (k-1);
    wo[n] = res;
    return res;
}

long long wf(int n, int k) {
    if (n == 1)
        return 0;
    long long res = w[n];
    if (res == 0)
        res = wof(n-1, k);
    w[n] = res;
    return res;
}

long long kountf(int n, int k) {
    if (n == 1)
        return k-1;
    long long res = kount[n];
    if (res == 0)
        res = wf(n, k) + wof(n, k);
    kount[n] = res;
    return res;
}


int main() {
    int n;
    int k;
    cin >> n >> k;

    cout << kountf(n, k) << endl;
}
