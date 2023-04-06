#include <bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        map<char, int> m;

        char last = s[0];
        int count = 1;
        for (int i=1; i<s.size(); i++) {
            if (s[i] == last) {
                count++;
            } else {
                if (count & 1) {
                    m[last] = 1;
                }
                count = 1;
            }
            last = s[i];
        }
        if (count & 1) {
            m[last] = 1;
        }

        string res = "";
        for (auto x : m) {
            if (x.second == 1) {
                res += x.first;
            }
        }
        cout << res << endl;
    }
}
