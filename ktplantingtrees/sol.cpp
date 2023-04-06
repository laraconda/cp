#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> ns(n);
    vector<int> days(n);
    for (int i=0; i<n; i++) {
        int ti;
        cin >> ti;
        ns[i] = ti;
    }

    sort(ns.begin(), ns.end(), greater<int>());
    int mmax = -1;
    for (int i=0; i<n; i++) {
        days[i] = i + ns[i];
        mmax = max(days[i], mmax);
    }

    cout << mmax + 2 << endl; 
}
