#include <bits/stdc++.h>
using namespace std;

const long long MAXN = 1e10 + 1;

bitset<MAXN> s;
int main() {
    int n;
    cin >> n;

    s[0] = 1;
    s[1] = 1;
    for (int i=2; i <= sqrt(n); i++) {
        if (s[i])
            continue;
        for (int j=i*i; j<=n; j+=i)
            s[j] = 1;
    }

    for (int i=2; i<=n; i++) {
        if (!s[i])
            cout << i << " ";
    }
    cout << endl; 
}
