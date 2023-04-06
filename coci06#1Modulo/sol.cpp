#include <bits/stdc++.h>
using namespace std;

const int MOD = 42;
int a[MOD];

int main() {
    for (int i=0; i<10; i++) {
        int ni;
        cin >> ni;
        a[ni % MOD]++;
    }

    int ans = 0;
    for (int i=0; i<MOD; i++)
        if (a[i]) ans++;

    cout << ans << endl;
}
