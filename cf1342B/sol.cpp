#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        string t;
        cin >> t;
        int n = 0;
        for (int i=0; i<t.size(); i++) {
            n += t[i] - '0';
        }
        if (n ==0 || n == t.size())
            cout << t << endl;
        else {
            string s;
            int i=0;
            s.push_back(t[0]);
            while (s.size()<2*t.size()) s.push_back(s[i++] - '0' ? '0' : '1');
            cout << s << endl;
        }
    }
}
