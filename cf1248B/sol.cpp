#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;

    vector<int> ns(n);
    long long s = 0;
    for (int i=0; i<n; i++) {
        int ni;
        cin >> ni;
        ns[i] = ni;
        s += ni;
    }

    sort(ns.begin(), ns.end());
    reverse(ns.begin(), ns.end());

    long long s1 = 0;
    for (int i=0; i < (int)ceil((double)n/2); i++) {
        s1 += ns[i];
    }

    long long s2 = s - s1;

    long long res = pow(s1, 2) + pow(s2, 2);
    cout << res << endl;
}
