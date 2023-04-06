#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >>n >> m;
        set<int> s;
        for (int i=1; i<=n; i++) s.insert(i);
        while (m--) {
            int a, b, c;
            cin >> a >> b >> c;
            s.erase(b);
        }
        int x = *s.begin();
        for (int i=1; i<=n; i++) {
            if (i != x) {
                cout << i << " " << x << endl;
            }
        }
    }
}
