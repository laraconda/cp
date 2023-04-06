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

        string a, b;
        bool eq = true;
        for (int i=0; i<s.size(); i++) {
            if (eq) {
                if (s[i] == '0') {
                    a.push_back('0');
                    b.push_back('0');
                } else if (s[i] == '1') {
                    a.push_back('1');
                    b.push_back('0');
                    eq = false;
                } else if (s[i] == '2') {
                    a.push_back('1');
                    b.push_back('1');
                }
            } else {
                if (s[i] == '0') {
                    a.push_back('0');
                    b.push_back('0');
                } else if (s[i] == '1') {
                    a.push_back('0');
                    b.push_back('1');
                } else if (s[i] == '2') {
                    a.push_back('0');
                    b.push_back('2');
                }
            }
        }

        cout << a << endl;
        cout << b << endl;
    }
}
