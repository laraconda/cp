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

        string res = "NO";
        if (n < 11) {
            res = "NO";
        } else {
            for (int i = n-11; i>=0; i--) {
                if (s[i] == '8') {
                    res = "YES";
                    break;
                }
            }
        }

        cout << res << endl;
    }
}
