#include <bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int first = -1;
        int last = -1;
        for (int i=0; i < n;i++) {
            if (s[i] == '1') {
                if (first == -1) {
                    first = i;
                    last = i;
                } else
                    last = i;
            }
        }

        int res;
        if (first != -1) {    
            res = max((last + 1) * 2, (n - first) * 2);
        } else {
            res = n;
        }
    
        cout << res << endl;
    }
}
