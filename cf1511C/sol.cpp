#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        int ai;
        cin >> ai;
        a[i] = ai;
    }
    map<int, int> m;
    for (int i=n-1; i>=0; i--) {
        m[a[i]] = i;
    }
    for (int i = 0; i<q; i++) {
        int qi;
        cin >> qi;
        cout << m[qi] + 1 << " ";

        for (auto& x : m) if (x.second < m[qi])x.second += 1; 
        m[qi] = 0;
    }
    cout << endl;
}
