#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        int r = 0;
        for (int i=0; i<n; i++) {
           if (s[i] == 'A') r++;
           else if (r) r--;
           else r++;
        }
        cout << r << endl;
    }
}
