#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> a;
        for (int i=0; i<n; i++) {
            int ai;
            cin >> ai;
            a.push_back(ai);
        }
        bool pos = true;
        if (n < 2*x) {
            vector<int> b(a);
            sort(b.begin(), b.end());
            for (int i=0; i<n; i++) {
                if (i < n - x || n - 1- i < n - x) continue;
                if (b[i] != a[i]) pos = false;
            }
        }
        string r = "YES";
        if (!pos) r = "NO";
        cout << r << endl;
    }
}
