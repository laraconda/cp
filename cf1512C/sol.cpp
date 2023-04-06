#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        string s;
        cin >> s;

        for (int i=0; i<s.size(); i++) {
            if (s[i] == '0') a--;
            if (s[i] == '1') b--;
        }

        bool fail = false;
        for (int i=0; i<=(int)s.size()/2; i++) {
            int j = (int)s.size() - 1 - i;
            if (s[i] == '?' && s[j] != '?') {
                if (s[j] == '0') {
                    if (a >= 1) {
                        s[i] = '0';
                        a--;
                    } else fail = true;
                } else {
                    if (b >= 1) {
                        s[i] = '1';
                        b--;
                    }
                    else fail = true;
                }
            } else if (s[i] != '?' && s[j] == '?') {
                if (s[i] == '0') {
                    if (a >= 1) {
                        s[j] = '0';
                        a--;
                    } else fail = true;
                } else {
                    if (b >= 1) {
                        s[j] = '1';
                        b--;
                    } else fail = true;
                }
            } else if (s[i] != s[j]) {
                fail = true;
            }
        }
        for (int i=0; i<=(int)s.size()/2; i++) {
            int j = (int)s.size() - 1 - i;
            if (s[i] == '?' && s[j] == '?') {
                if (i == j) { 
                    if (a > 0) {
                        s[i] = '0';
                        a--;
                    } else if (b > 0) {
                        s[i] = '1';
                        b--;
                    } else fail = true;
                } else if (a >= 2) {
                    s[i] = '0';
                    s[j] = '0';
                    a-=2;
                } else if (b >= 2) {
                    s[i] = '1';
                    s[j] = '1';
                    b-=2;
                } else {
                    fail = true;
                }
            }
        }
        if (a != 0 || b != 0) fail = true;
        if (fail) cout << -1 << endl;
        else {
            for (int i=0; i<(int)s.size(); i++) {
                cout << s[i];
            }
            cout << endl;
        }
    }
}
