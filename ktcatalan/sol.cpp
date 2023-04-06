#include <bits/stdc++.h>
using namespace std;

// This is not a solution to this problem. Rather is a solution if a module was present in the problem statement.

const long long MOD = 1e9 + 7;
const int MXN = 5003;
long long cats[MXN];

void ccats() {
    cats[0] = cats[1] = 1;
    for (int i=2; i < MXN; i++) {
        cats[i] = 0;
        for (int j=0; j<i; j++) {
            cats[i] += (cats[j] * cats[i - j - 1]) % MOD;
            cats[i] %= MOD;
        }
    }
}

int main() {
    int q;
    cin >> q;

    ccats();
    while (q--) {
        int qi;
        cin >> qi;
        cout << cats[qi] << endl;
    }
}
